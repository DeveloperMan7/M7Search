//
//  GitHub: https://github.com/iphone5solo/M7Search
//  Created by DevMan7.
//  Copyright © 2019 iphone5solo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "M7SearchConst.h"

@class M7SearchViewController, M7SearchSuggestionViewController;

typedef void(^M7DidSearchBlock)(M7SearchViewController *searchViewController, UISearchBar *searchBar, NSString *searchText);

/**
 style of popular search
 */
typedef NS_ENUM(NSInteger, M7HotSearchStyle)  {
    M7HotSearchStyleNormalTag,      // normal tag without border
    M7HotSearchStyleColorfulTag,    // colorful tag without border, color of background is randrom and can be custom by `colorPol`
    M7HotSearchStyleBorderTag,      // border tag, color of background is `clearColor`
    M7HotSearchStyleARCBorderTag,   // broder tag with ARC, color of background is `clearColor`
    M7HotSearchStyleRankTag,        // rank tag, color of background can be custom by `rankTagBackgroundColorHexStrings`
    M7HotSearchStyleRectangleTag,   // rectangle tag, color of background is `clearColor`
    M7HotSearchStyleDefault = M7HotSearchStyleNormalTag // default is `M7HotSearchStyleNormalTag`
};

/**
 style of search history
 */
typedef NS_ENUM(NSInteger, M7SearchHistoryStyle) {
    M7SearchHistoryStyleCell,           // style of UITableViewCell
    M7SearchHistoryStyleNormalTag,      // style of M7HotSearchStyleNormalTag
    M7SearchHistoryStyleColorfulTag,    // style of M7HotSearchStyleColorfulTag
    M7SearchHistoryStyleBorderTag,      // style of M7HotSearchStyleBorderTag
    M7SearchHistoryStyleARCBorderTag,   // style of M7HotSearchStyleARCBorderTag
    M7SearchHistoryStyleDefault = M7SearchHistoryStyleCell // default is `M7SearchHistoryStyleCell`
};

/**
 mode of search result view controller display
 */
typedef NS_ENUM(NSInteger, M7SearchResultShowMode) {
    M7SearchResultShowModeCustom,   // custom, can be push or pop and so on.
    M7SearchResultShowModePush,     // push, dispaly the view of search result by push
    M7SearchResultShowModeEmbed,    // embed, dispaly the view of search result by embed
    M7SearchResultShowModeDefault = M7SearchResultShowModeCustom // defualt is `M7SearchResultShowModeCustom`
};
/**
 mode of search view controller display
 */
typedef NS_ENUM(NSInteger, M7SearchViewControllerShowMode) {
    M7SearchViewControllerShowModeModal,    // modal, dispaly the view of searchViewController by modal
    M7SearchViewControllerShowModePush,   // push, dispaly the view of searchViewController by push
    M7SearchViewControllerShowDefault = M7SearchViewControllerShowModeModal // defualt is `M7SearchViewControllerShowModeModal`
};


/**
 The protocol of data source, you can custom the suggestion view by implement these methods the data scource.
 */
@protocol M7SearchViewControllerDataSource <NSObject>

@optional

/**
 Return a `UITableViewCell` object.

 @param searchSuggestionView    view which display search suggestions
 @param indexPath               indexPath of row
 @return a `UITableViewCell` object
 */
- (UITableViewCell *)searchSuggestionView:(UITableView *)searchSuggestionView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

/**
 Return number of rows in section.

 @param searchSuggestionView    view which display search suggestions
 @param section                 index of section
 @return number of rows in section
 */
- (NSInteger)searchSuggestionView:(UITableView *)searchSuggestionView numberOfRowsInSection:(NSInteger)section;

/**
 Return number of sections in search suggestion view.

 @param searchSuggestionView    view which display search suggestions
 @return number of sections
 */
- (NSInteger)numberOfSectionsInSearchSuggestionView:(UITableView *)searchSuggestionView;

/**
 Return height for row.

 @param searchSuggestionView    view which display search suggestions
 @param indexPath               indexPath of row
 @return height of row
 */
- (CGFloat)searchSuggestionView:(UITableView *)searchSuggestionView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

@end


/**
 The protocol of delegate
 */
@protocol M7SearchViewControllerDelegate <NSObject, UITableViewDelegate>

@optional

/**
 Called when search begain.

 @param searchViewController    search view controller
 @param searchBar               search bar
 @param searchText              text for search
 */
- (void)searchViewController:(M7SearchViewController *)searchViewController
      didSearchWithSearchBar:(UISearchBar *)searchBar
                  searchText:(NSString *)searchText;

/**
 Called when popular search is selected.

 @param searchViewController    search view controller
 @param index                   index of tag
 @param searchText              text for search
 
 Note: `searchViewController:didSearchWithSearchBar:searchText:` will not be called when this method is implemented.
 */
- (void)searchViewController:(M7SearchViewController *)searchViewController
   didSelectHotSearchAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText;

/**
 Called when search history is selected.

 @param searchViewController    search view controller
 @param index                   index of tag or row
 @param searchText              text for search
 
 Note: `searchViewController:didSearchWithSearchBar:searchText:` will not be called when this method is implemented.
 */
- (void)searchViewController:(M7SearchViewController *)searchViewController
didSelectSearchHistoryAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText;

/**
 Called when search suggestion is selected.

 @param searchViewController    search view controller
 @param index                   index of row
 @param searchText              text for search

 Note: `searchViewController:didSearchWithSearchBar:searchText:` will not be called when this method is implemented.
 */
- (void)searchViewController:(M7SearchViewController *)searchViewController
didSelectSearchSuggestionAtIndex:(NSInteger)index
                  searchText:(NSString *)searchText M7SEARCH_DEPRECATED("Use searchViewController:didSelectSearchSuggestionAtIndexPath:searchText:");

/**
 Called when search suggestion is selected, the method support more custom of search suggestion view.

 @param searchViewController    search view controller
 @param indexPath               indexPath of row
 @param searchBar               search bar
 
 Note: `searchViewController:didSearchWithSearchBar:searchText:` and `searchViewController:didSelectSearchSuggestionAtIndex:searchText:` will not be called when this method is implemented.
 Suggestion: To ensure that can cache selected custom search suggestion records, you need to set `searchBar.text` = "custom search text".
 */
- (void)searchViewController:(M7SearchViewController *)searchViewController didSelectSearchSuggestionAtIndexPath:(NSIndexPath *)indexPath
                   searchBar:(UISearchBar *)searchBar;

/**
 Called when search text did change, you can reload data of suggestion view thought this method.

 @param searchViewController    search view controller
 @param searchBar               search bar
 @param searchText              text for search
 */
- (void)searchViewController:(M7SearchViewController *)searchViewController
         searchTextDidChange:(UISearchBar *)searchBar
                  searchText:(NSString *)searchText;

/**
 Called when cancel item did press, default execute `[self dismissViewControllerAnimated:YES completion:nil]`.

 @param searchViewController search view controller
 */
- (void)didClickCancel:(M7SearchViewController *)searchViewController;

/**
 Called when back item did press, default execute `[self.navigationController popViewControllerAnimated:YES]`.
 
 @param searchViewController search view controller
 */
- (void)didClickBack:(M7SearchViewController *)searchViewController;

@end

@interface M7SearchViewController : UIViewController

/**
 The delegate
 */
@property (nonatomic, weak) id<M7SearchViewControllerDelegate> delegate;

/**
 The data source
 */
@property (nonatomic, weak) id<M7SearchViewControllerDataSource> dataSource;

/**
 Ranking the background color of the corresponding hexadecimal string (eg: @"#ffcc99") array (just four colors) when `hotSearchStyle` is `M7HotSearchStyleRankTag`.
 */
@property (nonatomic, strong) NSArray<NSString *> *rankTagBackgroundColorHexStrings;

/**
 The pool of color which are use in colorful tag when `hotSearchStyle` is `M7HotSearchStyleColorfulTag`.
 */
@property (nonatomic, strong) NSMutableArray<UIColor *> *colorPol;

/**
 Whether swap the popular search and search history location, default is NO.
 
 Note: It is‘t effective when `searchHistoryStyle` is `M7SearchHistoryStyleCell`.
 */
@property (nonatomic, assign) BOOL swapHotSeachWithSearchHistory;

/**
 The element of popular search
 */
@property (nonatomic, copy) NSArray<NSString *> *hotSearches;

/**
 The tags of popular search
 */
@property (nonatomic, copy) NSArray<UILabel *> *hotSearchTags;

/**
 The label of popular search header
 */
@property (nonatomic, weak) UILabel *hotSearchHeader;

/**
 Whether show popular search, default is YES.
 */
@property (nonatomic, assign) BOOL showHotSearch;

/**
 The title of popular search
 */
@property (nonatomic, copy) NSString *hotSearchTitle;

/**
 The tags of search history
 */
@property (nonatomic, copy) NSArray<UILabel *> *searchHistoryTags;

/**
 The label of search history header
 */
@property (nonatomic, weak) UILabel *searchHistoryHeader;

/**
 The title of search history
 */
@property (nonatomic, copy) NSString *searchHistoryTitle;

/**
 Whether show search history, default is YES.
 
 Note: search record is not cache when it is NO.
 */
@property (nonatomic, assign) BOOL showSearchHistory;

/**
 The path of cache search record, default is `M7SEARCH_SEARCH_HISTORY_CACHE_PATH`.
 */
@property (nonatomic, copy) NSString *searchHistoriesCachePath;

/**
 The number of cache search record, default is 20.
 */
@property (nonatomic, assign) NSUInteger searchHistoriesCount;

/**
 Whether remove the space of search string, default is YES.
 */
@property (nonatomic, assign) BOOL removeSpaceOnSearchString;

/**
 The button of empty search record when `searchHistoryStyle` is’t `M7SearchHistoryStyleCell`.
 */
@property (nonatomic, weak) UIButton *emptyButton;

/**
 The label od empty search record when `searchHistoryStyle` is `M7SearchHistoryStyleCell`.
 */
@property (nonatomic, weak) UILabel *emptySearchHistoryLabel;

/**
 The style of popular search, default is `M7HotSearchStyleNormalTag`.
 */
@property (nonatomic, assign) M7HotSearchStyle hotSearchStyle;

/**
 The style of search histrory, default is `M7SearchHistoryStyleCell`.
 */
@property (nonatomic, assign) M7SearchHistoryStyle searchHistoryStyle;

/**
 The mode of display search result view controller, default is `M7SearchResultShowModeCustom`.
 */
@property (nonatomic, assign) M7SearchResultShowMode searchResultShowMode;

/**
 The mode of display search view controller, default is `M7SearchViewControllerShowModeModal`.
 */
@property (nonatomic, assign) M7SearchViewControllerShowMode searchViewControllerShowMode;

/**
 The search bar
 */
@property (nonatomic, weak) UISearchBar *searchBar;

/**
 The text field of search bar
 */
@property (nonatomic, weak) UITextField *searchTextField;

/**
 The background color of search bar.
 */
@property (nonatomic, strong) UIColor *searchBarBackgroundColor;

/**
 The cornerRadius of `_UISearchBarSearchFieldBackgroundView` which from `self.searchTextField.subviews`, default is 0.0.
 */
@property (nonatomic, assign) CGFloat searchBarCornerRadius;

/**
 The barButtonItem of cancel
 */
@property (nonatomic, strong) UIBarButtonItem *cancelBarButtonItem;

/**
 The customView of cancelBarButtonItem
 */
@property (nonatomic, weak) UIButton *cancelButton;

/**
 The barButtonItem of back
 */
@property (nonatomic, strong) UIBarButtonItem *backBarButtonItem;

/**
 The customView of backBarButtonItem
 */
@property (nonatomic, weak) UIButton *backButton;

/**
 The search suggestion view
 */
@property (nonatomic, weak, readonly) UITableView *searchSuggestionView;

/**
 The block which invoked when search begain.
 */
@property (nonatomic, copy) M7DidSearchBlock didSearchBlock;

/**
 The element of search suggestions
 
 Note: it is't effective when `searchSuggestionHidden` is NO or cell of suggestion view is custom.
 */
@property (nonatomic, copy) NSArray<NSString *> *searchSuggestions;

/**
 Whether hidden search suggstion view, default is NO.
 */
@property (nonatomic, assign) BOOL searchSuggestionHidden;

/**
 The view controller of search result.
 */
@property (nonatomic, strong) UIViewController *searchResultController;

/**
 Whether show search result view when search text did change, default is NO.
 
 Note: it is effective only when `searchResultShowMode` is `M7SearchResultShowModeEmbed`.
 */
@property (nonatomic, assign) BOOL showSearchResultWhenSearchTextChanged;

/**
 Whether show search result view when search bar become first responder again.
 
 Note: it is effective only when `searchResultShowMode` is `M7SearchResultShowModeEmbed`.
 */
@property (nonatomic, assign) BOOL showSearchResultWhenSearchBarRefocused;

/**
 Whether show keyboard when return to search result, default is YES.
 */
@property (nonatomic, assign) BOOL showKeyboardWhenReturnSearchResult;

/**
 Creates an instance of searchViewContoller with popular searches and search bar's placeholder.

 @param hotSearches     popular searchs
 @param placeholder     placeholder of search bar
 @return new instance of `M7SearchViewController` class
 */
+ (instancetype)searchViewControllerWithHotSearches:(NSArray<NSString *> *)hotSearches
                               searchBarPlaceholder:(NSString *)placeholder;

/**
 Creates an instance of searchViewContoller with popular searches, search bar's placeholder and the block which invoked when search begain.

 @param hotSearches     popular searchs
 @param placeholder     placeholder of search bar
 @param block           block which invoked when search begain
 @return new instance of `M7SearchViewController` class
 
 Note: The `delegate` has a priority greater than the `block`, `block` is't effective when `searchViewController:didSearchWithSearchBar:searchText:` is implemented.
 */
+ (instancetype)searchViewControllerWithHotSearches:(NSArray<NSString *> *)hotSearches
                               searchBarPlaceholder:(NSString *)placeholder
                                     didSearchBlock:(M7DidSearchBlock)block;

@end
