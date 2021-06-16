//
//  ViewController.m
//  UIViewtable协议
//
//  Created by 张佳乔 on 2021/6/14.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //创建数据视图对象
    _tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 40, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height) style:UITableViewStyleGrouped];
    
    //设置代理对象
    _tableView.delegate = self;
    //设置数据代理对象
    _tableView.dataSource = self;
    //数据视图显示
    [self.view addSubview:_tableView];
    
    _arrayData = [[NSMutableArray alloc] init];
    
    for (int i = 'A'; i <= 'Z'; i++) {
        
        //定义小数组
        NSMutableArray* arraySmall = [[NSMutableArray alloc] init];
        
        for (int j = 1; j <= 5; j++) {
            
            NSString* str = [NSString stringWithFormat:@"%c%d", i, j];
        
            [arraySmall addObject:str];
        }
        
        //生成一个二维数组
        [_arrayData addObject:arraySmall];
    }
    
}

//获取组数
- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView {
    return _arrayData.count;
}

//获取每组元素的个数
- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    NSInteger numRow = [[_arrayData objectAtIndex:section] count];
    
    return numRow;
}

//创建单元格
- (UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSString* str = @"cell";
    
    UITableViewCell* cell = [_tableView dequeueReusableCellWithIdentifier:str];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:str];
    }
    
    cell.textLabel.text = _arrayData[indexPath.section][indexPath.row];
    
    return cell;
}

//获取每个单元格高度
- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 100;
}

//获取每组的头部标题
- (NSString*) tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    return @"头部标题";
}

//获取每组尾部标题
- (NSString*) tableView:(UITableView *)tableView titleForFooterInSection:(NSInteger)section {
    return @"尾部标题";
}

//获取头部高度
- (CGFloat) tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section {
    return 40;
}

//获取尾部高度
- (CGFloat) tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    return 60;
}


@end
