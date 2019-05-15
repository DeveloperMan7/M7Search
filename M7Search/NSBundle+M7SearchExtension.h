//
//  GitHub: https://github.com/iphone5solo/M7Search
//  Created by DevMan7.
//  Copyright © 2019 iphone5solo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface NSBundle (M7SearchExtension)

/**
 Get the localized string

 @param key     key for localized string
 @return a localized string
 */
+ (NSString *)py_localizedStringForKey:(NSString *)key;

/**
 Get the path of `M7Search.bundle`.

 @return path of the `M7Search.bundle`
 */
+ (NSBundle *)py_searchBundle;

/**
 Get the image in the `M7Search.bundle` path

 @param name name of image
 @return a image
 */
+ (UIImage *)py_imageNamed:(NSString *)name;

@end
