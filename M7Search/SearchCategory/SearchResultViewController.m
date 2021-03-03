//
//  SearchResultViewController.m
//  K12Online
//
//  Created by DevMan7 on 2020/4/22.
//  Copyright © 2020 AppCoda. All rights reserved.
//

#import "SearchResultViewController.h"

@interface SearchResultViewController ()<UITableViewDelegate,UITableViewDataSource>
@property (nonatomic,strong) UITableView *tableView;
@end

@implementation SearchResultViewController
- (void)viewDidLoad {
    [super viewDidLoad];

    [self.view addSubview:self.tableView];
    // Do any additional setup after loading the view.
}
-(void)viewWillLayoutSubviews{
    [super viewWillLayoutSubviews];
    [self.tableView setFrame:self.view.bounds];
}
#pragma mark - UITableViewDelegate,UITableViewDataSource -

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    return nil;
}
-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    return nil;

}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    //    return self.dataArray.count;
    return 33;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 1;
}
-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{

    return 1;
}
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 50;
}
-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{

}
#pragma mark - Lazy load
-(UITableView *)tableView
{
    if (!_tableView) {
        _tableView = [[UITableView alloc]initWithFrame:CGRectZero style:UITableViewStylePlain];
        [_tableView setBackgroundColor:[UIColor clearColor]];
        _tableView.delegate = self;
        _tableView.dataSource = self;
        _tableView.showsVerticalScrollIndicator = NO;
        _tableView.estimatedRowHeight = 50;
        _tableView.separatorStyle = UITableViewCellAccessoryNone;
    }
    return _tableView;
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
