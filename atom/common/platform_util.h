// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_COMMON_PLATFORM_UTIL_H_
#define ATOM_COMMON_PLATFORM_UTIL_H_

#include <string>
#include <vector>
#include <map>


#include "base/callback_forward.h"
#include "build/build_config.h"

#if defined(OS_WIN)
#include "base/strings/string16.h"
#endif

class GURL;

namespace base {
class FilePath;
}

namespace platform_util {

typedef base::Callback<void(const std::string&)> OpenExternalCallback;

// Show the given file in a file manager. If possible, select the file.
// Must be called from the UI thread.
bool ShowItemInFolder(const base::FilePath& full_path);

// Open the given file in the desktop's default manner.
// Must be called from the UI thread.
bool OpenItem(const base::FilePath& full_path);

// Open the given external protocol URL in the desktop's default manner.
// (For example, mailto: URLs in the default mail user agent.)
bool OpenExternal(
#if defined(OS_WIN)
    const base::string16& url,
#else
    const GURL& url,
#endif
    bool activate);

// The asynchronous version of OpenExternal.
void OpenExternal(
#if defined(OS_WIN)
    const base::string16& url,
#else
    const GURL& url,
#endif
    bool activate,
    const OpenExternalCallback& callback);

// Move a file to trash.
bool MoveItemToTrash(const base::FilePath& full_path);
typedef std::vector<unsigned long> PROCESSIDVECTOR;
typedef std::vector<unsigned long>::iterator PROCESSIDVECTOR_ITOR;
void Beep();
#if defined(OS_WIN)
bool FindProcessbyName(const base::string16&);
bool FindProcessbyContainName(const base::string16&);
bool FindHudProcess();
bool KillProcessbyName(const base::string16&);
bool CheckProcessPathAndFiles(const base::string16&, const std::vector<base::string16>&, const bool);
int GetFileDir(wchar_t *fullPath, wchar_t *);
bool FindProcessLocation(unsigned long processId, wchar_t* pPathProcess);
PROCESSIDVECTOR GetProcessNamedList(const wchar_t*);
std::vector<base::string16> GetProcessDirectorys(const base::string16&);
std::vector<base::string16> GetDirectoryItems(const base::string16&);
std::vector<base::string16> GetProcessList();
#endif

}  // namespace platform_util

#endif  // ATOM_COMMON_PLATFORM_UTIL_H_
