////
////  CommonMacro.h
////  Demo
////
////  Created by shaw on 2020/3/26.
////  Copyright © 2020 shaw. All rights reserved.
////
//
#ifndef CommonMacro_h
#define CommonMacro_h

#pragma mark
#define IsEmptyString(str)      ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )
#define IsEmptyArray(array)     (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)
#define IsEmptyDict(dic)        (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)
#define IsEmptyObject(_object)  (_object == nil || [_object isKindOfClass:[NSNull class]] || ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) || ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))
#define IsNilOrNull(_ref)  (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) || ([(_ref) isEqual:@"null"]) || ([(_ref) isEqual:@"(null)"]))

#pragma mark
#define IsiPhone    ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)
#define IsiPad      ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define IsIphoneX   (ScreenHeight >= 812.0f && IsiPhone)


#define CurrentLanguage             ([[NSLocale preferredLanguages] objectAtIndex:0])
#define IsLanguage(l)               [currentLanguage hasPrefix:l]
#define IsLanguageEn                IsLanguage(@"en")

#define NavBarHeight      (IsIphoneX ? (44 + 44) : (20 + 44))
#define TabBarHeight    (IsIphoneX ? (49 + 34) : 49)


#pragma mark
#define WidthAdapteRate_6   ScreenWidth/375.0
#define HeightAdapteRate_6  ScreenHeight/667.0
#define SuitHeight(value)   HeightAdapteRate_6 * (value)
#define SuitWidth(value)    WidthAdapteRate_6 * (value)


#pragma mark
#define DocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
#define TempPath NSTemporaryDirectory()
#define CachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

#define LocalString(x, ...) NSLocalizedString(x, nil)

#define SystemFont(FONTSIZE)      [UIFont systemFontOfSize:FONTSIZE]


#pragma mark
#define AppVersion  [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]
#define SystemVersion                             ([[[UIDevice currentDevice] systemVersion] floatValue])
#define SystemVersionEqualTo(v)                   ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SystemVersionHigherThan(v)               ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SystemVersionEqualOrHigherThan(v)        ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SystemVersionLowerThan(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SystemVersionEqualOrLowerThan(v)      ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)


#pragma mark
#define ImageOfBundle(name,extension)    [UIImage imageWithContentOfFile: [[NSBundle mainBundle] pathForResource:name ofType:extension]]
#define ImageBundle(name) ([UIImage imageWithContentOfFile: [[NSBundle mainBundle] pathForResource:name ofType:nil]])
#define ImageNamed(name) ([UIImage imageNamed:name])


#pragma mark
#define RGB(r,g,b)                  [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:1.f]
#define RGBA(r,g,b,a)               [UIColor colorWithRed:r / 255.f green:g / 255.f blue:b / 255.f alpha:a]
#define RGB_hex(hex)                RGBA((float)((hex & 0xFF0000) >> 16),(float)((hex & 0xFF00) >> 8),(float)(hex & 0xFF),1.f)
#define RGBA_hex(hex,a)             RGBA((float)((hex & 0xFF0000) >> 16),(float)((hex & 0xFF00) >> 8),(float)(hex & 0xFF),a)
#define RandomColor                 RGB(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))
#define ClearColor                  [UIColor clearColor]


#pragma mark
#define StartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();
#define EndTime   NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)


#pragma mark
#define screenWidth ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)
#define ScreenHeight ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)
#define ScreenSize ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)


#pragma mark
#define GlobalGCD(block)           dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)
#define MainGCD(block)             dispatch_async(dispatch_get_main_queue(), block)

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)


#pragma mark
#define DegreesToRadian(x)      (M_PI * (x) / 180.0)
#define RadianToDegrees(radian) (radian * 180.0) / (M_PI)

#pragma mark
#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

// strong self
#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

#pragma mark
#define SharedApplication [UIApplication sharedApplication]
#define SharedKeyWindow [UIApplication sharedApplication].keyWindow
#define SharedAppDelegate [UIApplication sharedApplication].delegate
#define SharedUserDefaults [NSUserDefaults standardUserDefaults]
#define SharedNotificationCenter [NSNotificationCenter defaultCenter]


#pragma mark
#define MailSend(email) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"mailto://%@",email]])

#define PhoneCall(phone) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"tel://%@",phone]])

#define PhoneCallAuto(phone) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"telprompt://%@",phone]])

#define SMSSend(phone) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"sms://%@",phone]])

#define SafariOpen(url) ([[UIApplication sharedApplication] openURL:[NSURL URLWithString:url])


#pragma mark

#ifdef DEBUG //打开LOG功能

#define PPFile  [NSString stringWithFormat:@"%s", __FILE__].lastPathComponent
//打印出所在文件名，所在行，堆栈地址
#define PPLog(...) printf("%s: %p (line = %d): %s\n\n", [PPFile UTF8String] , &self, __LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String]);

#else //关闭LOG功能
#define PPLog(s, ...)
#endif

//系统宏介绍：
//
// __LINE__：宏在预编译时会替换成当前的行号
//
// __FUNCTION__：宏在预编译时会替换成当前的函数名称
//
//__VA_ARGS__：简单的说，就是将左边…的内容替换进来

//
//#if TARGET_OS_IOS
//    NSLog(@"真机测试")
//#endif
//
//#if TARGET_IPHONE_SIMULATOR
//    NSLog(@"模拟器")
//#endif
//
//
//#ifdef DEBUG
//（debug 模式下的配置）
//#else
//（release 模式下的配置）
//#endif
//
//
#endif /* CommonMacro_h */
