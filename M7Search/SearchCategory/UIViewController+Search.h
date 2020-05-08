//
//  UIViewController+Search.h
//  K12Online
//
//  Created by DevMan7 on 2020/4/22.
//  Copyright © 2020 AppCoda. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "M7Search.h"
#import "SearchResultViewController.h"
NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (Search)<M7SearchViewControllerDelegate>
-(void)presentSearchViewController;
@end

NS_ASSUME_NONNULL_END
