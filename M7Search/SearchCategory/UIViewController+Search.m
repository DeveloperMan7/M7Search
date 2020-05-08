//
//  UIViewController+Search.m
//  K12Online
//
//  Created by DevMan7 on 2020/4/22.
//  CoM7right © 2020 AppCoda. All rights reserved.
//

#import "UIViewController+Search.h"

@implementation UIViewController (Search)
-(void)presentSearchViewController{
    // 1. Create hotSearches array
    NSArray *hotSeaches = @[@"EEC",@"牛人带你磨“爆“课",@"Civa", @"online",@"混合教学师训",@"运营"];
    // 2. Create searchViewController
    M7SearchViewController *searchViewController = [M7SearchViewController searchViewControllerWithHotSearches:hotSeaches searchBarPlaceholder:@"请输入您要查找的课程名" didSearchBlock:^(M7SearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText) {
        // Call this Block when completion search automatically
        // Such as: Push to a view controller
        SearchResultViewController *VC = [[SearchResultViewController alloc]init];
        VC.keyWord = searchText;
        searchViewController.searchResultController = VC;
    }];
    searchViewController.delegate = self;
    searchViewController.navBarBgAlpha = @"0.0";
    searchViewController.searchResultShowMode = M7SearchResultShowModeEmbed;
    if (@available(iOS 13.0, *)) {
        searchViewController.searchTextField.attributedPlaceholder = [[NSMutableAttributedString alloc] initWithString:searchViewController.searchTextField.placeholder attributes:@{NSForegroundColorAttributeName : ColorWithHexString(@"999999"),NSFontAttributeName : font(28)}];

    }else{
        [searchViewController.searchTextField setValue:ColorWithHexString(@"999999") forKeyPath:@"_placeholderLabel.textColor"];
        [searchViewController.searchTextField setValue:font(28) forKeyPath:@"_placeholderLabel.font"];
    }
    [searchViewController.searchTextField setBackgroundColor:[UIColor whiteColor]];
    searchViewController.searchTextField.textColor= ColorWithHexString(@"333333");
    searchViewController.searchTextField.font = font(28);
    
    searchViewController.searchBar.layer.cornerRadius = 8;
    searchViewController.searchBar.layer.masksToBounds = YES;
    searchViewController.searchBar.tintColor = [UIColor colorWithHexString:@"156ADA"];
    [searchViewController.searchBar becomeFirstResponder];
    
    searchViewController.searchViewControllerShowMode = M7SearchViewControllerShowModePush;
    [self.navigationController pushViewController:searchViewController animated:YES];
}
#pragma mark M7SearchViewControllerDelegate
-(void)didClickCancel:(M7SearchViewController *)searchViewController{
    [self.navigationController popViewControllerAnimated:NO];
}
@end
