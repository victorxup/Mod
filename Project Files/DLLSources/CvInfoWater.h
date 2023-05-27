#pragma once

//  $Header:
//------------------------------------------------------------------------------------------------
//
//  FILE:    CvInfosWater.h
//
//  AUTHOR:	tomw
//
//
//  PURPOSE: All Civ4 info classes and the base class for them
//
//------------------------------------------------------------------------------------------------
//  Copyright (c) 2003 Firaxis Games, Inc. All rights reserved.
//------------------------------------------------------------------------------------------------
#ifndef CV_WATERINFO_H
#define CV_WATERINFO_H

#include "CvInfos.h"
#include "CvEnums.h"

#pragma warning( disable: 4251 )		// needs to have dll-interface to be used by clients of class

class CvXMLLoadUtility;


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//  class : CvWaterPlaneInfo
//
//  DESC:
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CvWaterPlaneInfo :public CvInfoBase
{
public:

	__declspec(dllexport) CvWaterPlaneInfo();
	__declspec(dllexport) virtual ~CvWaterPlaneInfo();

	__declspec(dllexport) float getMaterialAlpha() const;				// The water plane's material alpha

	__declspec(dllexport) float getTextureScaling() const;				// The water plane's texture scale
	__declspec(dllexport) float getTextureScrollRateU() const;			// The water plane's texture scroll rate in U
	__declspec(dllexport) float getTextureScrollRateV() const;			// The water plane's texture scroll rate in V

	__declspec(dllexport) char const* getBaseTexture() const;
	__declspec(dllexport) char const* getNormalTexture() const;
	__declspec(dllexport) char const* getTransitionTexture() const;
	__declspec(dllexport) char const* getEnvironmentTexture() const;
	__declspec(dllexport) char const* getGridTexture() const;

	__declspec(dllexport) bool read(CvXMLLoadUtility*);

protected:

	float m_fMaterialAlpha;			// The water plane's material alpha

	CvString m_szBaseTexture;		// The filename of the base texture
	CvString m_szNormalTexture;		// The filename of the normal texture
	CvString m_szTransitionTexture;	// The filename of the transition texture
	CvString m_szEnvironmentTexture;	// The filename of the transition texture
	CvString m_szGridTexture;	// The filename of the transition texture

	float m_BaseTextureScale;		// Texture scaling
	float m_fURate;					// Texture scroll rate
	float m_fVRate;
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//  class : CvTerrainPlaneInfo
//
//  DESC:
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CvTerrainPlaneInfo :public CvInfoBase
{
public:

	__declspec(dllexport) CvTerrainPlaneInfo();
	__declspec(dllexport) virtual ~CvTerrainPlaneInfo();

	__declspec(dllexport) bool isVisible() const;				// The terrain plane's material alpha
	__declspec(dllexport) bool isGroundPlane() const;				// The terrain plane's material alpha
	__declspec(dllexport) bool isCitySelection() const;				// The terrain plane's material alpha
	__declspec(dllexport) float getMaterialAlpha() const;				// The terrain plane's material alpha
	__declspec(dllexport) float getCloseAlpha() const;				// The terrain plane's material alpha

	__declspec(dllexport) float getTextureScalingU() const;				// The terrain plane's texture scale
	__declspec(dllexport) float getTextureScalingV() const;				// The terrain plane's texture scale
	__declspec(dllexport) float getTextureScrollRateU() const;			// The terrain plane's texture scroll rate in U
	__declspec(dllexport) float getTextureScrollRateV() const;			// The terrain plane's texture scroll rate in V
	__declspec(dllexport) float getZHeight() const;						// The terrain plane's z height in world units
	__declspec(dllexport) FogTypes getFogType() const;

	__declspec(dllexport) char const* getBaseTexture() const;
	__declspec(dllexport) void setBaseTexture(char const* szVal);		// The filename of the base texture

	__declspec(dllexport) bool read(CvXMLLoadUtility*);

protected:

	bool m_bVisible;
	bool m_bGroundPlane;
	bool m_bCitySelection;
	float m_fMaterialAlpha;			// The terrain plane's material alpha
	float m_fCloseAlpha;

	CvString m_szBaseTexture;		// The filename of the base texture

	float m_BaseTextureScaleU;		// Texture scaling
	float m_BaseTextureScaleV;		// Texture scaling
	float m_fURate;					// Texture scroll rate
	float m_fVRate;
	float m_fZHeight;
	FogTypes m_eFogType;
};


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//  class : CvTerrainPlaneInfo
//
//  DESC:
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class CvCameraOverlayInfo :public CvInfoBase
{
public:

	__declspec(dllexport) CvCameraOverlayInfo();
	__declspec(dllexport) virtual ~CvCameraOverlayInfo();

	__declspec(dllexport) bool isVisible() const;				// The terrain plane's material alpha
	__declspec(dllexport) CameraOverlayTypes getCameraOverlayType() const;

	__declspec(dllexport) char const* getBaseTexture() const;
	__declspec(dllexport) void setBaseTexture(char const* szVal);		// The filename of the base texture

	__declspec(dllexport) bool read(CvXMLLoadUtility*);

protected:

	bool m_bVisible;
	CvString m_szBaseTexture;		// The filename of the base texture
	CameraOverlayTypes m_eCameraOverlayType;
};


#endif
