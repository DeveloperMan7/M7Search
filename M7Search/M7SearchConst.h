//
//  GitHub: https://github.com/iphone5solo/M7Search
//  Created by DevMan7.
//  Copyright © 2019 iphone5solo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "UIView+M7SearchExtension.h"
#import "UIColor+M7SearchExtension.h"
#import "NSBundle+M7SearchExtension.h"

#define M7SEARCH_MARGIN 10
#define M7SEARCH_BACKGROUND_COLOR M7SEARCH_COLOR(255, 255, 255)

#ifdef DEBUG
#define M7SEARCH_LOG(...) NSLog(__VA_ARGS__)
#else
#define M7SEARCH_LOG(...)
#endif

#define M7SEARCH_COLOR(r,g,b) [UIColor colorWithRed:(r/255.0) green:(g/255.0) blue:(b/255.0) alpha:1.0]
#define M7SEARCH_RANDOM_COLOR  M7SEARCH_COLOR(arc4random_uniform(256),arc4random_uniform(256),arc4random_uniform(256))

#define M7SEARCH_DEPRECATED(instead) NS_DEPRECATED(2_0, 2_0, 2_0, 2_0, instead)

#define M7SEARCH_REALY_SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define M7SEARCH_REALY_SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define M7ScreenW (M7SEARCH_REALY_SCREEN_WIDTH < M7SEARCH_REALY_SCREEN_HEIGHT ? M7SEARCH_REALY_SCREEN_WIDTH : M7SEARCH_REALY_SCREEN_HEIGHT)
#define M7ScreenH (M7SEARCH_REALY_SCREEN_WIDTH > M7SEARCH_REALY_SCREEN_HEIGHT ? M7SEARCH_REALY_SCREEN_WIDTH : M7SEARCH_REALY_SCREEN_HEIGHT)
#define M7SEARCH_SCREEN_SIZE CGSizeMake(M7ScreenW, M7ScreenH)

#define M7SEARCH_SEARCH_HISTORY_CACHE_PATH [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"M7Searchhistories.plist"] // the path of search record cached

UIKIT_EXTERN NSString *const M7SearchSearchPlaceholderText;
UIKIT_EXTERN NSString *const M7SearchHotSearchText;
UIKIT_EXTERN NSString *const M7SearchSearchHistoryText;
UIKIT_EXTERN NSString *const M7SearchEmptySearchHistoryText;
UIKIT_EXTERN NSString *const M7SearchEmptyButtonText;
UIKIT_EXTERN NSString *const M7SearchEmptySearchHistoryLogText;
UIKIT_EXTERN NSString *const M7SearchCancelButtonText;
UIKIT_EXTERN NSString *const M7SearchBackButtonText;
