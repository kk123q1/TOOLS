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
//
//	File:
//		PISelection.h
//
//	Copyright 1996-2000, Adobe Systems Incorporated.
//	All Rights Reserved.
//
//	Distribution:
//		PUBLIC
//
//	Description:
//		This file describes version 1.0 of Photoshop's selection plug-in module
//		interface.
//
//	Use:
//		Include in all Selection plug-ins.
//		
//
//	Version history:
//		Version 1.0.0	10/9/1997	Ace		Initial compilation.
//		
//		
//
//-------------------------------------------------------------------------------
// $Id: //photoshop/8.0/photoshop/sharedinterfaces/PISelection.h#1 $ 
// $DateTime: 2003/07/08 15:07:21 $ 
// $Change: 75352 $ 
// $Author: byer $ 

#ifndef __PISelection__
#define __PISelection__

#if PRAGMA_ONCE
#pragma once
#endif

#include "PIActions.h"
#include "PIGeneral.h"
#include "SPBasic.h"

/********************************************************************************/

/* Operation selectors */

#define selectionSelectorAbout 	 0
#define selectionSelectorExecute 1

/********************************************************************************/

/* Error return values. The plug-in module may also return standard Macintosh
   operating system error codes, or report its own errors, in which case it
   can return any positive integer. */
   
#define selectionBadParameters -30700	/* "a problem with the selection module interface" */
#define selectionBadMode	   -30701	/* "the selection module does not support <mode> images" */

/********************************************************************************/

typedef struct PISelectionParams
	{
	
	/* We start with the fields that are common to pretty much all of the plug-ins. */
	
	int32		serialNumber;		/* DEPRECATED - Formerly the host serial number.
									   The host will now report
									   zero for the serialNumber. Plug-ins should use 
									   the PropertySuite and specify 'propSerialString2'
									   to get the serial string. */

	TestAbortProc	abortProc;		/* The plug-in module may call this no-argument
									   BOOLEAN function (using Pascal calling
									   conventions) several times a second during long
									   operations to allow the user to abort the operation.
									   If it returns TRUE, the operation should be aborted
									   (and a positive error code returned). */

	ProgressProc	progressProc;	/* The plug-in module may call this two-argument
									   procedure periodically to update a progress
									   indicator.  The first parameter is the number
									   of operations completed; the second is the total
									   number of operations. */

	OSType		hostSig;			/* Creator code for host application */
	HostProc	hostProc;			/* Host specific callback procedure */

	BufferProcs *bufferProcs;		/* The host buffer procedures. */
	
	ResourceProcs *resourceProcs;	/* The host plug-in resource procedures. */
	
	ProcessEventProc processEvent;	/* Pass event to the application. */
	
	DisplayPixelsProc displayPixels;/* Display dithered pixels. */

	HandleProcs	*handleProcs;		/* Platform independent handle manipulation. */

	ColorServicesProc colorServices; /* Routine to access color services. */
	
	ImageServicesProcs *imageServicesProcs;
									/* Suite of image processing callbacks. */
			
	PropertyProcs	*propertyProcs;	/*	Routines to query and set document and
										view properties. The plug-in needs to
										dispose of the handle returned for
										complex properties (the plug-in also
										maintains ownership of handles for
										set properties.
									*/
									
	ChannelPortProcs *channelPortProcs;
									/* Suite for passing pixels through channel ports. */
			
	PIDescriptorParameters	*descriptorParameters;	/* For recording and playback */
	Str255					*errorString;			/* For silent and errReportString */
	
	PlugInMonitor	monitor;		/* Information on current monitor */

	void 		*platformData;		/* Platform specific information. */

	char reserved [4];				/* 4 bytes of reserved space. */
	
	/* We follow this with the fields specific to this type of plug-in. */
	
	ReadImageDocumentDesc *documentInfo;	/* The document for the selection. */
	
	WriteChannelDesc *newSelection;			/* A place to write the new selection. */
	
	Handle newPath;							/* The plug-in can return a path instead of
											a selection. If the plug-in makes this handle
											non-null, any data written into the new
											selection will be ignored and the path described
											by the handle becomes the work path. The
											handle will be disposed of by the host. */
											
	/* We can optionally take the mask and use it to build a new layer or floating
	selection filled with the current foreground color. 
	 0 = make selection
	 1 = make path
	 2 = make layer/float */
	
	int32 treatment;
	
	int32 supportedTreatments; /* Mask indicating host supported treatments. */
	
	SPBasicSuite *sSPBasic;		/* SuitePea basic suite */
	void		*plugInRef;		/* plugin reference used by SuitePea*/
											
	/* And, of course, space for future expansion. */
	
	char reservedBlock [248];
			
	}
PISelectionParams, *SelectionRecordPtr;

/********************************************************************************/

#define piSelMakeMask			0
#define piSelMakeWorkPath		1
#define piSelMakeLayer			2

/********************************************************************************/

#endif // __PISelection_h__ 
