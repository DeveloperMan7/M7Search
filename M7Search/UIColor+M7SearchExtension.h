//
//  GitHub: https://github.com/iphone5solo/M7Search
//  Created by DevMan7.
//  Copyright © 2019 iphone5solo. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (M7SearchExtension)

/**
 Returns the corresponding color according to the hexadecimal string.

 @param hexString   hexadecimal string(eg:@"#ccff88")
 @return new instance of `UIColor` class
 */
+ (instancetype)py_colorWithHexString:(NSString *)hexString;

/**
  Returns the corresponding color according to the hexadecimal string and alpha.

 @param hexString   hexadecimal string(eg:@"#ccff88")
 @param alpha       alpha
 @return new instance of `UIColor` class
 */
+ (instancetype)py_colorWithHexString:(NSString *)hexString alpha:(CGFloat)alpha;

@end
