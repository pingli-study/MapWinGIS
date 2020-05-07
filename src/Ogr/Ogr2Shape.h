#pragma once
#include "ogr_feature.h"
#include "OgrHelper.h"
#include <set>
#include "OgrLabels.h"

class Ogr2Shape
{
public:
	static IShapefile* CreateShapefile(OGRLayer* layer, ShpfileType activeShapeType);
	static IShapefile* Layer2Shapefile(OGRLayer* layer, ShpfileType activeShapeType, int maxFeatureCount, bool& isTrimmed, OgrDynamicLoader* loader, ICallback* callback = NULL, bool addFeatureStyle = true);
	static bool FillShapefile(OGRLayer* layer, IShapefile* sf, int maxFeatureCount, bool loadLabels, ICallback* callback, bool& isTrimmed, bool addFeatureStyle = true);
	static void ReadGeometryTypes(OGRLayer* layer, set<OGRwkbGeometryType>& types, bool readAll);
	static void GeometryTypesToShapeTypes(set<OGRwkbGeometryType>& types, vector<ShpfileType>& result);
    static bool ExtendShapefile(OGRLayer* layer, IShapefile* sf, bool loadLabels, ICallback* callback, bool addFeatureStyle = true);
private:
	static void CopyValues(OGRFeatureDefn* poFields, OGRFeature* poFeature, IShapefile* sf, bool hasFID, long numShapes, bool loadLabels, OgrLabelsHelper::LabelFields labelFields, bool addFeatureStyle = true);
	static void CopyFields(OGRLayer* layer, IShapefile* sf);
	
};

