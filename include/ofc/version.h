/* Copyright (c) 2021 Connected Way, LLC. All rights reserved.
 * Use of this source code is governed by a Creative Commons 
 * Attribution-NoDerivatives 4.0 International license that can be
 * found in the LICENSE file.
 */
#if !defined(__VERSION_H__)
#define __VERSION_H__

/**
 * \defgroup version Open Files Version
 *
 * These defines can be used to identify the version of the framework 
 * in use.  These will be updated periodically.
 */

/** \{ */

/**
 * Major version.  Defines a major rewrite of the software.  
 *
 * For historical purposes, the major versions so far have been:
 *
 * - 1.* Original CIFS stack based on a book by Chris Hertel (2000-2005)
 * - 2.* Rewrite the framework core (2005-2006)
 * - 3.* Rewrite of the CIFS stack (2006-2015)
 * - 4.* Rebrand to ConnectedSMB, Add Android/iOS (2015-2021)
 * - 5.* Rebrand to Open Files, Change build/packaging (2021-present)
 */
#define OFC_SHARE_MAJOR 5
/**
 * Minor Version.  Updated with new functionality.  
 *
 * Currently we are at the initial release of OpenFiles 5
 */
#define OFC_SHARE_MINOR 3
/**
 * Tag or patch level.
 *
 * May be a commit id, tag, or id.
 */
#define OFC_SHARE_TAG "5"

/** \} */

#endif
