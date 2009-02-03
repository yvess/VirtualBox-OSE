/*
 * Copyright (C) 2005 Mike McCormack
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/*
 * Sun LGPL Disclaimer: For the avoidance of doubt, except that if any license choice
 * other than GPL or LGPL is available it will apply instead, Sun elects to use only
 * the Lesser General Public License version 2.1 (LGPLv2) at this time for any software where
 * a choice of LGPL license versions is made available with the language indicating
 * that LGPLv2 or any later version may be used, or where a choice of which version
 * of the LGPL is applied is otherwise unspecified.
 */

#ifndef __WINE_ODBCINST_H
#define __WINE_ODBCINST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <sql.h>

/* flags for Installer function requests */
#define ODBC_INSTALL_INQUIRY 	1
#define ODBC_INSTALL_COMPLETE	2

#define ODBC_INSTALL_DRIVER	1
#define ODBC_REMOVE_DRIVER	2
#define ODBC_CONFIG_DRIVER	3
#define ODBC_CONFIG_DRIVER_MAX  100

#define ODBC_ADD_DSN            1
#define ODBC_CONFIG_DSN         2
#define ODBC_REMOVE_DSN         3
#define ODBC_ADD_SYS_DSN        4
#define ODBC_CONFIG_SYS_DSN     5
#define ODBC_REMOVE_SYS_DSN     6
#define ODBC_REMOVE_DEFAULT_DSN 7

/* Mode values for SQLSetConfigMode/SQLGetConfigMode */
#define ODBC_BOTH_DSN 0
#define ODBC_USER_DSN 1
#define ODBC_SYSTEM_DSN 2

/* error values */
#define ODBC_ERROR_GENERAL_ERR			1
#define ODBC_ERROR_INVALID_BUFF_LEN		2
#define ODBC_ERROR_INVALID_HWND			3
#define ODBC_ERROR_INVALID_STR			4
#define ODBC_ERROR_INVALID_REQUEST_TYPE		5
#define ODBC_ERROR_COMPONENT_NOT_FOUND		6
#define ODBC_ERROR_INVALID_NAME			7
#define ODBC_ERROR_INVALID_KEYWORD_VALUE	8
#define ODBC_ERROR_INVALID_DSN			9
#define ODBC_ERROR_INVALID_INF			10
#define ODBC_ERROR_REQUEST_FAILED		11
#define ODBC_ERROR_INVALID_PATH			12
#define ODBC_ERROR_LOAD_LIB_FAILED		13
#define ODBC_ERROR_INVALID_PARAM_SEQUENCE	14
#define ODBC_ERROR_INVALID_LOG_FILE		15
#define ODBC_ERROR_USER_CANCELED		16
#define ODBC_ERROR_USAGE_UPDATE_FAILED		17
#define ODBC_ERROR_CREATE_DSN_FAILED		18
#define ODBC_ERROR_WRITING_SYSINFO_FAILED	19
#define ODBC_ERROR_REMOVE_DSN_FAILED		20
#define ODBC_ERROR_OUT_OF_MEM			21
#define ODBC_ERROR_OUTPUT_STRING_TRUNCATED	22


BOOL WINAPI ODBCCPlApplet(LONG,LONG,LONG*,LONG*);
BOOL WINAPI SQLConfigDataSource(HWND,WORD,LPCSTR,LPCSTR);
BOOL WINAPI SQLConfigDataSourceW(HWND,WORD,LPCWSTR,LPCWSTR);
BOOL WINAPI SQLConfigDriver(HWND,WORD,LPCSTR,LPCSTR,LPSTR,WORD,WORD*);
BOOL WINAPI SQLConfigDriverW(HWND,WORD,LPCWSTR,LPCWSTR,LPWSTR,WORD,WORD*);
BOOL WINAPI SQLCreateDataSource(HWND,LPCSTR);
BOOL WINAPI SQLCreateDataSourceW(HWND,LPCWSTR);
BOOL WINAPI SQLGetAvailableDrivers(LPCSTR,LPSTR,WORD,WORD*);
BOOL WINAPI SQLGetAvailableDriversW(LPCWSTR,LPWSTR,WORD,WORD*);
BOOL WINAPI SQLGetConfigMode(UWORD*);
BOOL WINAPI SQLGetInstalledDrivers(LPSTR,WORD,WORD*);
BOOL WINAPI SQLGetInstalledDriversW(LPWSTR,WORD,WORD*);
int WINAPI SQLGetPrivateProfileString(LPCSTR,LPCSTR,LPCSTR,LPCSTR,int,LPCSTR);
int WINAPI SQLGetPrivateProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR,int,LPCWSTR);
BOOL WINAPI SQLGetTranslator(HWND,LPSTR,WORD,WORD*,LPSTR,WORD,WORD*,DWORD*);
BOOL WINAPI SQLGetTranslatorW(HWND,LPWSTR,WORD,WORD*,LPWSTR,WORD,WORD*,DWORD*);
BOOL WINAPI SQLInstallDriver(LPCSTR,LPCSTR,LPSTR,WORD,WORD*);
BOOL WINAPI SQLInstallDriverW(LPCWSTR,LPCWSTR,LPWSTR,WORD,WORD*);
BOOL WINAPI SQLInstallDriverEx(LPCSTR,LPCSTR,LPSTR,WORD,WORD*,WORD,LPDWORD);
BOOL WINAPI SQLInstallDriverExW(LPCWSTR,LPCWSTR,LPWSTR,WORD,WORD*,WORD,LPDWORD);
BOOL WINAPI SQLInstallDriverManager(LPSTR,WORD,WORD*);
BOOL WINAPI SQLInstallDriverManagerW(LPWSTR,WORD,WORD*);
SQLRETURN WINAPI SQLInstallerError(WORD,DWORD*,LPSTR,WORD,WORD*);
SQLRETURN WINAPI SQLInstallerErrorW(WORD,DWORD*,LPWSTR,WORD,WORD*);
BOOL WINAPI SQLInstallODBC(HWND,LPCSTR,LPCSTR,LPCSTR);
BOOL WINAPI SQLInstallODBCW(HWND,LPCWSTR,LPCWSTR,LPCWSTR);
BOOL WINAPI SQLInstallTranslatorEx(LPCSTR,LPCSTR,LPSTR,WORD,WORD*,WORD,LPDWORD);
BOOL WINAPI SQLInstallTranslatorExW(LPCWSTR,LPCWSTR,LPWSTR,WORD,WORD*,WORD,LPDWORD);
BOOL WINAPI SQLInstallTranslator(LPCSTR,LPCSTR,LPCSTR,LPSTR,WORD,WORD*,WORD,LPDWORD);
BOOL WINAPI SQLInstallTranslatorW(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,WORD,WORD*,WORD,LPDWORD);
BOOL WINAPI SQLManageDataSources(HWND hwnd);
SQLRETURN WINAPI SQLPostInstallerError(DWORD,LPCSTR);
SQLRETURN WINAPI SQLPostInstallerErrorW(DWORD,LPCWSTR);
BOOL WINAPI SQLReadFileDSN(LPCSTR,LPCSTR,LPCSTR,LPSTR,WORD,WORD*);
BOOL WINAPI SQLReadFileDSNW(LPCWSTR,LPCWSTR,LPCWSTR,LPWSTR,WORD,WORD*);
BOOL WINAPI SQLRemoveDefaultDataSource(void);
BOOL WINAPI SQLRemoveDriver(LPCSTR,BOOL,LPDWORD);
BOOL WINAPI SQLRemoveDriverW(LPCWSTR,BOOL,LPDWORD);
BOOL WINAPI SQLRemoveDriverManager(LPDWORD);
BOOL WINAPI SQLRemoveDSNFromIni(LPCSTR);
BOOL WINAPI SQLRemoveDSNFromIniW(LPCWSTR);
BOOL WINAPI SQLRemoveTranslator(LPCSTR,LPDWORD);
BOOL WINAPI SQLRemoveTranslatorW(LPCWSTR,LPDWORD);
BOOL WINAPI SQLSetConfigMode(UWORD);
BOOL WINAPI SQLValidDSN(LPCSTR);
BOOL WINAPI SQLValidDSNW(LPCWSTR);
BOOL WINAPI SQLWriteDSNToIni(LPCSTR,LPCSTR);
BOOL WINAPI SQLWriteDSNToIniW(LPCWSTR,LPCWSTR);
BOOL WINAPI SQLWriteFileDSN(LPCSTR,LPCSTR,LPCSTR,LPCSTR);
BOOL WINAPI SQLWriteFileDSNW(LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR);
BOOL WINAPI SQLWritePrivateProfileString(LPCSTR,LPCSTR,LPCSTR,LPCSTR);
BOOL WINAPI SQLWritePrivateProfileStringW(LPCWSTR,LPCWSTR,LPCWSTR,LPCWSTR);

#ifdef __cplusplus
}
#endif

#endif /*__WINE_ODBCINST_H*/
