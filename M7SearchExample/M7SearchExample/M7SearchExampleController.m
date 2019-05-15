//
//  GitHub: https://github.com/iphone5solo/M7Search
//  Created by DevMan7.
//  Copyright © 2019 iphone5solo. All rights reserved.
//

#import "M7SearchExampleController.h"
#import "M7Search.h"
#import "M7TempViewController.h"

@interface M7SearchExampleController () <M7SearchViewControllerDelegate>

@end

@implementation M7SearchExampleController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // set title
    self.title = @"M7Search Example";
    self.tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStyleGrouped];
    if ([self.tableView respondsToSelector:@selector(setCellLayoutMarginsFollowReadableWidth:)]) { // Adjust for iPad
        self.tableView.cellLayoutMarginsFollowReadableWidth = NO;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 2;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return section ? 5 : 6;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [[UITableViewCell alloc] init];
    if (0 == indexPath.section) {
        cell.textLabel.text = @[@"M7HotSearchStyleDefault", @"M7HotSearchStyleColorfulTag", @"M7HotSearchStyleBorderTag", @"M7HotSearchStyleARCBorderTag", @"M7HotSearchStyleRankTag", @"M7HotSearchStyleRectangleTag"][indexPath.row];
    } else {
        cell.textLabel.text = @[@"M7SearchHistoryStyleDefault", @"M7SearchHistoryStyleNormalTag", @"M7SearchHistoryStyleColorfulTag", @"M7SearchHistoryStyleBorderTag", @"M7SearchHistoryStyleARCBorderTag"][indexPath.row];
    }
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // 1. Create an Array of popular search
    NSArray *hotSeaches = @[@"Java", @"Python", @"Objective-C", @"Swift", @"C", @"C++", @"PHP", @"C#", @"Perl", @"Go", @"JavaScript", @"R", @"Ruby", @"MATLAB"];
    // 2. Create a search view controller
    M7SearchViewController *searchViewController = [M7SearchViewController searchViewControllerWithHotSearches:hotSeaches searchBarPlaceholder:NSLocalizedString(@"M7ExampleSearchPlaceholderText", @"搜索编程语言") didSearchBlock:^(M7SearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText) {
        // Called when search begain.
        // eg：Push to a temp view controller
        [searchViewController.navigationController pushViewController:[[M7TempViewController alloc] init] animated:YES];
    }];
    // 3. Set style for popular search and search history
    if (0 == indexPath.section) {
        searchViewController.hotSearchStyle = (NSInteger)indexPath.row;
        searchViewController.searchHistoryStyle = M7HotSearchStyleDefault;
    } else {
        searchViewController.hotSearchStyle = M7HotSearchStyleDefault;
        searchViewController.searchHistoryStyle = (NSInteger)indexPath.row; 
    }
    // 4. Set delegate
    searchViewController.delegate = self;
    // 5. Present(Modal) or push search view controller
    // Present(Modal)
//    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:searchViewController];
//    [self presentViewController:nav animated:YES completion:nil];
    // Push
    // Set mode of show search view controller, default is `M7SearchViewControllerShowModeModal`
    searchViewController.searchViewControllerShowMode = M7SearchViewControllerShowModePush;
//    // Push search view controller
    [self.navigationController pushViewController:searchViewController animated:YES];
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section
{
    return section ? NSLocalizedString(@"M7ExampleTableSectionZeroTitle", @"选择搜索历史风格（热门搜索为默认风格)") : NSLocalizedString(@"M7ExampleTableSectionZeroTitle", @"选择热门搜索风格（搜索历史为默认风格)");
}

#pragma mark - M7SearchViewControllerDelegate
- (void)searchViewController:(M7SearchViewController *)searchViewController searchTextDidChange:(UISearchBar *)seachBar searchText:(NSString *)searchText
{
    if (searchText.length) {
        // Simulate a send request to get a search suggestions
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.25 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            NSMutableArray *searchSuggestionsM = [NSMutableArray array];
            for (int i = 0; i < arc4random_uniform(5) + 10; i++) {
                NSString *searchSuggestion = [NSString stringWithFormat:@"Search suggestion %d", i];
                [searchSuggestionsM addObject:searchSuggestion];
            }
            // Refresh and display the search suggustions
            searchViewController.searchSuggestions = searchSuggestionsM;
        });
    }
}
@end
