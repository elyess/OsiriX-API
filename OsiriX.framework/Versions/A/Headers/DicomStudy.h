/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - LGPL
  
  See http://www.osirix-viewer.com/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/


#import <Cocoa/Cocoa.h>

@class DicomSeries, DicomImage;

/** \brief  Core Data Entity for a Study */
@interface DicomStudy : NSManagedObject
{
	BOOL isHidden;
	NSNumber *dicomTime, *cachedRawNoFiles;
    NSUInteger _numberOfImagesWhenCachedModalities;
	NSString *cachedModalites, *cacheYearOldAcquisition, *cacheYearOld;
    NSColor *cachedColor;
    NSArray *cachedPresentationStates;
    NSArray *cacheROIs __deprecated_msg("only in OsiriX");
    NSManagedObject *cachedROISRSeries __deprecated_msg("only in OsiriX");
    NSSet *cacheKeyImages __deprecated_msg("only in OsiriX");
    BOOL reentry;
}

@property(nonatomic, retain) NSString* accessionNumber;
@property(nonatomic, retain) NSString* color;
@property(nonatomic, retain) NSString* studyState;
@property(nonatomic, retain) NSString* comment;
@property(nonatomic, retain) NSString* comment2;
@property(nonatomic, retain) NSString* comment3;
@property(nonatomic, retain) NSString* comment4;
@property(nonatomic, retain) NSDate* date;
@property(nonatomic, retain) NSDate* dateAdded;
@property(nonatomic, retain) NSDate* dateOfBirth;
@property(nonatomic, retain) NSDate* dateOpened;
@property(nonatomic, retain) NSString* dictateURL;
@property(nonatomic, retain) NSNumber* expanded;
@property(nonatomic, retain) NSNumber* hasDICOM;
@property(nonatomic, retain) NSNumber* hasKeyImages __deprecated_msg("only in OsiriX");
@property(nonatomic, retain) NSNumber* hasROIs __deprecated_msg("only in OsiriX");
@property(nonatomic, retain) NSString* id;
@property(nonatomic, retain) NSString* institutionName;
@property(nonatomic, retain) NSNumber* lockedStudy;
@property(nonatomic, retain) NSString* modality;
@property(nonatomic, retain) NSString* name;
@property(nonatomic, retain) NSNumber* numberOfImages;
@property(nonatomic, retain) NSString* patientID;
@property(nonatomic, retain) NSString* patientSex;
@property(nonatomic, retain) NSString* patientUID;
@property(nonatomic, retain) NSString* performingPhysician;
@property(nonatomic, retain) NSString* referringPhysician;
@property(nonatomic, retain) NSString* reportURL;
@property(nonatomic, retain) NSNumber* stateText;
@property(nonatomic, retain) NSString* studyInstanceUID;
@property(nonatomic, retain) NSString* studyName;
@property(nonatomic, retain) NSData* windowsState;
@property(nonatomic, retain) NSSet* albums;
@property(nonatomic, retain) NSSet* series;

+ (NSRecursiveLock*) dbModifyLock;
+ (NSString*) formattedPatientName: (NSString*) n;
+ (NSString*) soundex: (NSString*) s;
- (NSString*) soundex;
+ (NSString*) yearOldFromDateOfBirth: (NSDate*) dateOfBirth;
+ (NSString*) yearOldAcquisition:(NSDate*) acquisitionDate FromDateOfBirth: (NSDate*) dateOfBirth;
+ (BOOL) displaySeriesWithSOPClassUID: (NSString*) uid andSeriesDescription: (NSString*) description;
+ (NSArray*) seriesSortDescriptors;
+ (NSArray*) seriesSortDescriptorsWithSubKey: (NSString*) subKey;
+ (NSArray*) seriesSortDescriptorsWithSubKey: (NSString*) subKey addStudyDateSorting: (BOOL) addStudyDateSorting;
+ (void) resetPreferences;
- (NSNumber*) noFiles;
- (NSSet*) paths;
- (NSSet*) keyImages;
- (NSArray*) roiAndKeyImages;
- (NSString*) yearOld;
- (NSString*) yearOldAcquisition;
- (NSSet*) images;
- (NSNumber*) rawNoFiles;
- (NSString*) modalities;
+ (NSString*) displayedModalitiesForSeries: (NSArray*) seriesModalities;
+ (NSArray*) chronologicalColors;
- (NSNumber*) chronologicalNumber;
- (NSColor*) chronologicalColor;
- (NSArray*) imageSeries;
- (NSArray*) imageSeriesContainingPixels:(BOOL) pixels;
- (NSArray*) imageSeriesContainingPixels:(BOOL) pixels includeLocalizersSeries: (BOOL) includeLocalizersSeries;
- (NSArray*) keyObjectSeries;
- (NSArray*) keyObjects;
- (NSArray*) presentationStateSeries;
- (NSArray*) presentationStateObjects;
- (NSArray*) presentationStateDictionaries;
- (NSArray*) waveFormSeries;
- (NSString*) roiPathForImage: (DicomImage*) image inArray: (NSArray*) roisArray;
- (NSString*) roiPathForImage: (DicomImage*) image;
- (DicomImage*) roiForImage: (DicomImage*) image inArray: (NSArray*) roisArray;
- (DicomSeries*) roiSRSeries;
- (DicomSeries*) localizersSeries;
- (DicomSeries*) reportSRSeries;
- (DicomImage*) windowsStateImage;
- (DicomSeries*) windowsStateSRSeries;
- (DicomImage*) reportImage;
- (DicomImage*) annotationsSRImage;
- (void) archiveReportAsDICOMSR;
- (void) archiveAnnotationsAsDICOMSR;
- (void) archiveWindowsStateAsDICOMSR;
- (NSArray*) allWindowsStateSRSeries;
- (BOOL) isHidden;
- (BOOL) isDistant;
- (NSNumber*) dicomTime;
- (void) setHidden: (BOOL) h;
- (NSNumber*) noFilesExcludingMultiFrames;
- (NSDictionary*) annotationsAsDictionary;
- (void) applyAnnotationsFromDictionary: (NSDictionary*) rootDict;
- (void) reapplyAnnotationsFromDICOMSR;
- (NSComparisonResult) compareName:(DicomStudy*)study;
- (NSArray*) roiImages;
- (NSArray*) imagesWithROIs __deprecated_msg("only in OsiriX");
- (NSArray*) allSeries;
- (NSArray*) generateDICOMSCImagesForKeyImages: (BOOL) keyImages andROIImages: (BOOL) ROIImages;
- (void) setNSColor:(NSColor *)c;
- (NSColor*) NSColor;
- (NSString*) ROIsDescription;
- (NSString*) type;
- (NSString*) calledAET; // Match DCMTKQueryNode
- (NSString*) callingAET; // Match DCMTKQueryNode
- (NSString *)hostname; // Match DCMTKQueryNode
+ (NSArray*) comparativeStudiesForStudy: (id) studySelectedID;
- (NSArray*) studiesForThisPatient;
- (BOOL) computeHasROIs __deprecated_msg("only in OsiriX");
- (BOOL) computeHasKeyImages __deprecated_msg("only in OsiriX");
- (NSImage*) thumbnailImage __deprecated_msg("only in OsiriX");
- (NSData*) thumbnail __deprecated_msg("only in OsiriX");
@end

@interface DicomStudy (CoreDataGeneratedAccessors)

- (void) addAlbumsObject:(NSManagedObject*) value;
- (void) removeAlbumsObject:(NSManagedObject*) value;
- (void) addAlbums:(NSSet*) value;
- (void) removeAlbums:(NSSet*) value;

- (void) addSeriesObject:(DicomSeries*) value;
- (void) removeSeriesObject:(DicomSeries*) value;
- (void) addSeries:(NSSet*) value;
- (void) removeSeries:(NSSet*) value;

- (NSArray*) imagesForKeyImages:(BOOL) keyImages andForROIs:(BOOL)alsoImagesWithROIs;

+ (NSString*) scrambleString: (NSString*) t;

@end

