# Electron API For Chivas Application (API version 4)

> Create and control browser windows.

## Window Process API

Process: Main, Renderer

```javascript
// In the main process.
const { electron } = require('electron')

const currentWindow = electron.remote.getCurrentWindow();
cureentWindow.setWindowPosFlags(0,102);

cureentWindow.setTopPos();

electron.shell.findHudProcess()

electron.shell.findProcessByName('chrome.exe')

electron.shell.findProcessByContainName('chrome')

electron.shell.killProcessByName('indicator.exe')
```

# Window Arrangement

## BrowserWindow

- window Arrangement API Added

#### `setWindowPosFlags(hWndInsertAfter, uFlags)` _win32_
window position and attibute change, win32 API [SetWindowPos](https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-setwindowpos) mapping.
hWndInsertAfter, uFlags both must be number

#### `setTopPos()` _Win32_ _MacOS_
Move top positon, regardless focus


# Window Process 

#### `findHudProcess()` _Win32_ _MacOS_
check process 'HoldemIndicator.exe' is running

#### `findProcessByName(processName)` _Win32_ _MacOS_
check process that have `[processName]` name is running
* Return Value
    - process is running: true
    - process is not running: false
    

#### `findProcessByContainName(keyword)` _Win32_ _MacOS_
check process that have keyword in process name is running
* Return Value
    - process is running: true
    - process is not running: false

#### `killProcessByName(processName)` _Win32_ _MacOS_
try kill process that have [processName]

#### `getProcessList()` _Win32_ _MacOS_
return array of whole process name list
 Return Value
    - Array<string>

#### `getProccessDirectoryList(processName)` _Win32_ _MacOS_ _[API4 Only]_
return array of whole process locations
 Return Value
    - Array<string>
```js
const { electron } = require('electron')

let processLocations = electron.remote.getProccessDirectoryList('chrome.exe');
//return ["C:\Program Files (x86)\Google\Chrome\Application", "C:\Program Files (x86)\AdvancedPokerTools\AdvancedGGNetConverter"]

```
