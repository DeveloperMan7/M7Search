//
//  SearchResultViewController.m
//  K12Online
//
//  Created by DevMan7 on 2020/4/22.
//  Copyright © 2020 AppCoda. All rights reserved.
//

#import "SearchResultViewController.h"
#import "BSBottomCell.h"
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
    CGRect frame = self.view.bounds;
    frame.origin.x = w(40);
    frame.size.width = self.view.width - w(80);
    [self.tableView setFrame:frame];
}
#pragma mark - UITableViewDelegate,UITableViewDataSource -

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    BSBottomCell *cell = [tableView dequeueReusableCellWithIdentifier:@"itemCell"];
    if (cell == nil) {
        cell = [[BSBottomCell alloc]initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"itemCell"];
    }
    [cell.imageView setImage:Image(@"位图")];
    [cell.textLabel setText:@"第二届“新浪教育·Civa杯”全 国教师技能大赛总决赛"];
    cell.textLabel.numberOfLines = 2;
    [cell.textLabel setFont:fontBold(30)];
    [cell.detailTextLabel setText:@"2020-02-15 12:40"];
    cell.detailTextLabel.numberOfLines = 1;
    [cell.detailTextLabel setFont:font(24)];
    cell.detailTextLabel.textColor = [UIColor colorWithHexString:@"666666"];
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    return cell;
}
-(UIView *)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section{
    UIView *v = nil;
    if (section==0) {
        UILabel *lb= [UILabel new];
        lb.textAlignment = NSTextAlignmentLeft;
        [lb setText:@"共128篇"];
        [lb setFont:font(24)];
        [lb setTextColor:[UIColor colorWithHexString:@"666666"]];
        [lb setBackgroundColor:[UIColor whiteColor]];
        return lb;
    }
    v = [UIView new];
    return v;

}
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    //    return self.dataArray.count;
    return 33;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return 1;
}
-(CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section{
    if (section==0) {
        return w(83);
    }
    return w(50);
}
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return w(157);
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
        _tableView.estimatedRowHeight = w(157);
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
