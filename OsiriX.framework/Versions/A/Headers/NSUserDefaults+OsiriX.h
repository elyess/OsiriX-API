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

typedef enum  UseScreenPart
{
    entireScreen = 0,
    leftPart,
    rightPart,
    twoThirdLeft,
    twoThirdRight
    
} UseScreenPart;

@interface NSUserDefaults (OsiriX)

#pragma mark General

extern NSString* const OsirixDateTimeFormatDefaultsKey;
+(NSDateFormatter*)dateTimeFormatter;
+(NSString*)formatDateTime:(NSDate*)date;

extern NSString* const OsirixDateFormatDefaultsKey;
+(NSDateFormatter*)dateFormatter;
+(NSString*)formatDate:(NSDate*)date;

extern NSString* const OsirixCanActivateDefaultDatabaseOnlyDefaultsKey;
+(BOOL)canActivateOnlyDefaultDatabase;
+(BOOL)canActivateAnyLocalDatabase;

extern NSString* const O2NonViewerScreensDefaultsKey;
#ifdef OSIRIX_VIEWER
-(NSArray*)screensUsedForViewers;
-(BOOL)screenIsUsedForViewers:(NSScreen*)screen;
-(void)screen:(NSScreen*)screen setIsUsedForViewers:(BOOL)flag;
-(UseScreenPart) screenPartForScreen: (NSScreen*) screen;
-(void) setScreenPart: (UseScreenPart) part forScreen: (NSScreen*) screen;
#endif

#pragma mark Bonjour Sharing

extern NSString* const OsirixBonjourSharingIsActiveDefaultsKey;
+(BOOL)bonjourSharingIsActive;

extern NSString* const OsirixBonjourSharingNameDefaultsKey;
+(NSString*)bonjourSharingName;
+(NSString*)defaultBonjourSharingName;

extern NSString* const OsirixBonjourSharingIsPasswordProtectedDefaultsKey;
+(BOOL)bonjourSharingIsPasswordProtected;

extern NSString* const OsirixBonjourSharingPasswordDefaultsKey;
+(NSString*)bonjourSharingPassword;

#pragma mark Web Portal

extern NSString* const OsirixWebPortalEnabledDefaultsKey;
+(BOOL)webPortalEnabled;

extern NSString* const OsirixWebPortalAddressDefaultsKey;
+(NSString*)webPortalAddress;
+(NSString*)defaultWebPortalAddress;

extern NSString* const OsirixWebPortalPortNumberDefaultsKey;
+(NSInteger)webPortalPortNumber;
+(NSInteger)defaultWebPortalPortNumber;

extern NSString* const OsirixWebPortalUsesSSLDefaultsKey;
+(BOOL)webPortalUsesSSL;

extern NSString* const OsirixWebPortalUsesWeasisDefaultsKey;
+(BOOL)webPortalUsesWeasis;

extern NSString* const OsirixWadoServiceEnabledDefaultsKey;
+(BOOL)wadoServiceEnabled;

extern NSString* const OsirixWebPortalPrefersFlashDefaultsKey;
+(BOOL)webPortalPrefersFlash;

extern NSString* const OsirixWebPortalPrefersCustomWebPagesKey;
+(BOOL)webPortalPrefersCustomWebPages;

extern NSString* const OsirixWebPortalNotificationsEnabledDefaultsKey;
+(BOOL)webPortalNotificationsEnabled;

extern NSString* const OsirixWebPortalNotificationsIntervalDefaultsKey;
+(NSInteger)webPortalNotificationsInterval;

extern NSString* const OsirixWebPortalRequiresAuthenticationDefaultsKey;
+(BOOL)webPortalRequiresAuthentication;

extern NSString* const OsirixWebPortalUsersCanRestorePasswordDefaultsKey;
+(BOOL)webPortalUsersCanRestorePassword;

// MARK: DICOM Communications

+ (NSString*)defaultAETitle;
+ (int)defaultAEPort;

@end
