// ADOBE SYSTEMS INCORPORATED
// Copyright  2002 - 2002 Adobe Systems Incorporated
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
//		PlusPlus.r
//
//	Description:
//		This file contains the resource text
//		for the Color Picker example module PlusPlus.
//
//	Use:
//		PlusPlus provides another color picker (available
//		from File: Preferences: General) that cycles through
//		four primary colors.  Once selected, clicking any
//		location that normally pops a picker (such as the
//		foreground or background color) will automatically
//		cycle to the next primary color.
//
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//	Definitions -- Required by include files.
//-------------------------------------------------------------------------------

// The About box and resources are created in DialogUtilities.r.
// You can easily override them, if you like.

#define plugInName			"PlusPlus"
#define plugInCopyrightYear	"2002"
#define plugInDescription \
	"An example plug-in color picker module for Adobe Photoshop�."

//-------------------------------------------------------------------------------
//	Definitions -- Required by other resources in this rez file.
//-------------------------------------------------------------------------------

// Dictionary (aete) resources:

#define vendorName			"AdobeSDK"
#define plugInAETEComment 	"PlusPlus example color picker plug-in"

#define plugInSuiteID		'sdK9'
#define plugInClassID		plugInSuiteID
#define plugInEventID		'pckR'

//-------------------------------------------------------------------------------
//	Set up included files for Macintosh and Windows.
//-------------------------------------------------------------------------------

#include "PIDefines.h"

#ifdef __PIMac__
	#include "Types.r"
	#include "SysTypes.r"
	#include "PIGeneral.r"
	#include "PIUtilities.r"
	#include "DialogUtilities.r"
#elif defined(__PIWin__)
	#include "PIGeneral.h"
	#include "PIUtilities.r"
	#include "WinDialogUtils.r"
#endif

#include "PIActions.h"

//-------------------------------------------------------------------------------
//	PiPL resource
//-------------------------------------------------------------------------------

resource 'PiPL' (ResourceID, plugInName " PiPL", purgeable)
{
    {
	    Kind { Picker },
	    Name { plugInName },
	    Category { vendorName },
	    Version { (latestPickerVersion << 16) | latestPickerSubVersion },
	    
		#ifdef __PIMac__
	        CodeCarbonPowerPC { 0, 0, "" },
		#elif defined (__PIWin__)
			CodeWin32X86 { "PluginMain" },
		#endif

		PickerID { vendorName " " plugInName },
		
		SupportedModes
		{
			doesSupportBitmap, doesSupportGrayScale,
			doesSupportIndexedColor, doesSupportRGBColor,
			doesSupportCMYKColor, doesSupportHSLColor,
			doesSupportHSBColor, doesSupportMultichannel,
			doesSupportDuotone, doesSupportLABColor
		},
				
		EnableInfo { "true" },
	}
};

//-------------------------------------------------------------------------------
//	Dictionary (scripting) resource
//-------------------------------------------------------------------------------

resource 'aete' (ResourceID, plugInName " dictionary", purgeable)
{
	1, 0, english, roman,							// aete version and language specifiers 
	{
		vendorName,									// vendor suite name 
		"Adobe example plug-ins",					// optional description 
		plugInSuiteID,									// suite ID 
		1,											// suite code, must be 1 
		1,											// suite level, must be 1 
		{											// structure for filters 
			vendorName " " plugInName,				// unique filter name 
			plugInAETEComment,						// optional description 
			plugInClassID,							// class ID, must be unique or Suite ID 
			plugInEventID,							// event ID, must be unique to class ID 
			
			NO_REPLY,								// never a reply 
			IMAGE_DIRECT_PARAMETER,					// direct parameter, used by Photoshop 
			{										// parameters here, if any 
				"amount",							// parameter name 
				keyAmount,							// parameter key ID 
				typeFloat,							// parameter type ID 
				"dissolve amount",					// optional description 
				flagsSingleParameter,				// parameter flags 
			},
		},
		{},											// non-filter plug-in class here 
		{},											// comparison ops (not supported) 
		{},											// any enumerations 
	},
};

//-------------------------------------------------------------------------------

// end PlusPlus.r
