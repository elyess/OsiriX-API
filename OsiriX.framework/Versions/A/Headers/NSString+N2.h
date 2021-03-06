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

#define WebPortalLocalized( key, comment) [key localizedForWebPortal]
#define N2NonNullString( a) a ? a : @""

@interface NSString (N2)

-(NSString*)stringBetweenString:(NSString*) aStr andString:(NSString*) bStr;
-(NSArray*)stringsBetweenString:(NSString*) aStr andString:(NSString*) bStr;
-(NSString*)markedString;
-(NSString*)stringByTruncatingToLength:(NSInteger)theWidth;
+(NSString*)sizeString:(unsigned long long)size;
+(NSString*)timeString:(NSTimeInterval)time;
+(NSString*)timeString:(NSTimeInterval)time maxUnits:(NSInteger)maxUnits;
+(NSString*)dateString:(NSTimeInterval)date;
-(NSString*)stringByTrimmingStartAndEnd;

-(NSString*)urlEncodedString;
-(NSString*)xmlEscapedString;
-(NSString*)xmlUnescapedString;

-(NSString*)ASCIIString;
-(NSString*)quotedPrintableString;
-(NSString*)txtToHtml;
-(NSString*)resolveNSLocalizedStrings;
-(NSString*)resolveNSLocalizedStringsForLanguage:(NSString*)language;
-(NSString*)resolveNSLocalizedStringsEscapeQuotationMarks: (BOOL) escapeQuotationMarks;
-(NSString*)resolveNSLocalizedStringsForLanguage:(NSString*)language inBundle:(NSBundle*)bundle;
-(NSString*)resolveNSLocalizedStringsForLanguage:(NSString*)language inBundle:(NSBundle*)bundle escapeQuotationMarks: (BOOL) escapeQuotationMarks;
-(NSString*)localizedForLanguage: (NSString*) language;
-(NSString*)localizedForWebPortal;

-(BOOL)contains:(NSString*)str;

-(NSString*)stringAfterString:(NSString*) aStr;
-(NSString*)stringByPrefixingLinesWithString:(NSString*)prefix;
+(NSString*)stringByRepeatingString:(NSString*)string times:(NSUInteger)times;
-(NSString*)suspendedString;
-(BOOL)validURL;
-(NSRange)range;

//-(NSString*)resolvedPathString;
-(NSString*)stringByComposingPathWithString:(NSString*)rel;

-(NSArray*)componentsWithLength:(NSUInteger)len;

-(BOOL)isEmail;

-(void)splitStringAtCharacterFromSet:(NSCharacterSet*)charset intoChunks:(NSString**)part1 :(NSString**)part2 separator:(unichar*)separator;

-(NSString*)md5;
-(NSString*)sha1 __deprecated_msg("only in OsiriX");
@end

@interface NSAttributedString (N2)

-(NSRange)range;

@end;
