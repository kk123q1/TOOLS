// ADOBE SYSTEMS INCORPORATED
// Copyright  1993 - 2002 Adobe Systems Incorporated
// All Rights Reserved
//
// NOTICE:  Adobe permits you to use, modify, and distribute this 
// file in accordance with the terms of the Adobe license agreement
// accompanying it.  If you have received this file from a source
// other than Adobe, then your use, modification, or distribution
// of it requires the prior written permission of Adobe.
//-------------------------------------------------------------------
//-------------------------------------------------------------------------------
//
//	File:
//		PIDebug.h
//
//	Description:
//		This file contains the prototypes and utilities
//		for plug-in debugging.
//
//	Use:
//		This particular file will define the debug flags to
//		build a debug version of the plug-in.
//
//-------------------------------------------------------------------------------

#ifndef __PIDebug_H__	// Has this not been defined yet?
#define __PIDebug_H__	// Only include this once by predefining it

/// Create a definition for debugging
#ifndef _DEBUG
#define _DEBUG	1
#endif

#endif // __PIDebug_H__
// end PIDebug.h