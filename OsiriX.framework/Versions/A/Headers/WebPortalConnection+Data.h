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

#import "WebPortalConnection.h"

@class DicomStudy;

@interface WebPortalConnection (Data)

+(NSArray*)MakeArray:(id)obj;

-(void)getWidth:(CGFloat*)width height:(CGFloat*)height fromImagesArray:(NSArray*)imagesArray;
-(void)getWidth:(CGFloat*)width height:(CGFloat*)height fromImagesArray:(NSArray*)imagesArray minSize:(NSSize)minSize maxSize:(NSSize)maxSize;

-(void)processLoginHtml;
-(void)processDoubleAuthenticationLoginHtml;
-(void)processIndexHtml;
-(void)processMainHtml;
-(void)processStudyListHtml;
-(void)processLogsListHtml;
-(void)processKeyROIsImagesHtml;
-(void)processSeriesHtml;
-(void)processStudyHtml;
-(void)processStudyHtml: (NSString*) xid;
-(void)processPasswordForgottenHtml;
-(void)processAccountHtml;
-(void)processClearCaches __deprecated_msg("only in OsiriX");

-(void)processAdminIndexHtml;
-(void)processAdminUserHtml;

-(void)processStudyListJson;
-(void)processSeriesJson;
-(void)processAlbumsJson;
-(void)processSeriesListJson;
-(void)processHTMLReportTemplate;
-(void)processHTMLReport;
-(void)processHTMLReportFrontMost2DViewerImage;
-(BOOL)processWado;

-(void)processWeasisJnlp;
-(void)processWeasisXml;

-(void)processThumbnail;
-(void)processReport;
-(void)processSeriesPdf;
-(void)processZip;
-(void)processImage;
-(void)processImageAsScreenCapture: (BOOL) asDisplayed;
-(void)processMovie;

-(id)objectWithXID:(NSString*)xid;
-(id)objectWithXID:(NSString*)xid compareToDistant: (BOOL) compareToDistant checkUserAutorisation: (BOOL) checkUserAutorisation;
-(void)receiveReportHtmlAsPOST;

-(void) addDoubleAuthenticationUserEvent: (NSString*) username;
-(NSTimeInterval) delayForDoubleAuthenticationUser: (NSString*) username;
- (void) resetDoubleAuthenticationEventsForUser:(NSString*) username;
@end

