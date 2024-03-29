/***********************************************************************/
/*                                                                     */
/* SPConfig.h                                                          */
/*                                                                     */
/* (c) Copyright 1995-1999, 2002 Adobe Systems Incorporated.                     */
/* All Rights Reserved.                                                */
/*                                                                     */
/* Patents Pending                                                     */
/*                                                                     */
/* NOTICE: All information contained herein is the property of Adobe   */
/* Systems Incorporated. Many of the intellectual and technical        */
/* concepts contained herein are proprietary to Adobe, are protected   */
/* as trade secrets, and are made available only to Adobe licensees    */
/* for their internal use. Any reproduction or dissemination of this   */
/* software is strictly forbidden unless prior written permission is   */
/* obtained from Adobe.                                                */
/*                                                                     */
/***********************************************************************/
/* $Id: $  */
/* $DateTime: $  */
/* $Change: $  */
/* $Author: $  */

/**

	SPConfig.h is the environment configuration file for Sweet Pea. It
	defines MAC_ENV or WIN_ENV. These are used to control platform-specific
	sections of code.

 **/

#ifndef __SPCnfig__
#define __SPCnfig__

/*
 *	Metrowerks MacOS 68K and PPC
 */
#ifdef __MWERKS__
#if !defined(__INTEL__)		/* mjf was- #if defined(__MC68K__) || defined(__POWERPC__) */
#ifndef MAC_ENV
#define MAC_ENV 1
#endif
#endif
#endif

/*
 *	Metrowerks Windows
 */
#ifdef __MWERKS__
#ifdef __INTEL__
#ifndef WIN_ENV
#define WIN_ENV 1
#include <x86_prefix.h>
#endif
#endif
#endif

/*
 *	Windows
 */
#if defined(_WINDOWS) || defined(_MSC_VER) || defined(WINDOWS)		// PSMod, better compiler check
#ifndef WIN_ENV
#define WIN_ENV 1
#endif
#endif

/*
 *	Make certain that one and only one of the platform constants is defined.
 */

#if !defined(WIN_ENV) && !defined(MAC_ENV)
#error
#endif

#if defined(WIN_ENV) && defined(MAC_ENV)
#error
#endif

#endif
