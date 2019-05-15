//
//  GitHub: https://github.com/iphone5solo/M7Search
//  Created by DevMan7.
//  Copyright © 2019 iphone5solo. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^M7SearchSuggestionDidSelectCellBlock)(UITableViewCell *selectedCell);

@protocol M7SearchSuggestionViewDataSource <NSObject, UITableViewDataSource>

@required
- (UITableViewCell *)searchSuggestionView:(UITableView *)searchSuggestionView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (NSInteger)searchSuggestionView:(UITableView *)searchSuggestionView numberOfRowsInSection:(NSInteger)section;
@optional
- (NSInteger)numberOfSectionsInSearchSuggestionView:(UITableView *)searchSuggestionView;
- (CGFloat)searchSuggestionView:(UITableView *)searchSuggestionView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

@end

@interface M7SearchSuggestionViewController : UITableViewController

@property (nonatomic, weak) id<M7SearchSuggestionViewDataSource> dataSource;
@property (nonatomic, copy) NSArray<NSString *> *searchSuggestions;
@property (nonatomic, copy) M7SearchSuggestionDidSelectCellBlock didSelectCellBlock;

+ (instancetype)searchSuggestionViewControllerWithDidSelectCellBlock:(M7SearchSuggestionDidSelectCellBlock)didSelectCellBlock;

@end
