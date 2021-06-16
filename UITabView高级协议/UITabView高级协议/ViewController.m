//
//  ViewController.m
//  UITabView高级协议
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
    
    _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    
    //自动调整子视图大小
    _tableView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    
    //设置代理
    _tableView.delegate = self;
    _tableView.dataSource = self;
    
    //数据视图的头部视图的设定
    _tableView.tableHeaderView = nil;
    //数据视图的尾部视图的设定
    _tableView.tableFooterView = nil;
    
    [self.view addSubview:_tableView];
    
    //初始化数据源数组
    _arrayData = [[NSMutableArray alloc] init];
    
    for (int i = 0; i < 20; i++) {
        NSString* str = [NSString stringWithFormat:@"A %d", i];
        
        [_arrayData addObject:str];
    }
    
    //当数据的数据源发生变化时，
    //更新数据视图，重新加载数据
    [_tableView reloadData];
    
    [self createButton];
    
}

- (void) createButton {
    _isEdit = NO;
    
    //创建功能按钮
    _buttonEdit = [[UIBarButtonItem alloc] initWithTitle:@"编辑" style:UIBarButtonItemStylePlain target:self action:@selector(pressEdit)];
    _buttonFinish = [[UIBarButtonItem alloc] initWithTitle:@"完成" style:UIBarButtonItemStylePlain target:self action:@selector(pressFinish)];
    _buttonDelete = [[UIBarButtonItem alloc] initWithTitle:@"删除" style:UIBarButtonItemStylePlain target:self action:@selector(pressDelete)];
    
    self.navigationItem.rightBarButtonItem = _buttonEdit;
    
    
}

//点击单元格时调用此协议函数
- (void) tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSLog(@"选中单元格！%ld，%ld", (long)indexPath.section, (long)indexPath.row);
}

//取消选中时调用此协议函数
- (void) tableView:(UITableView*)tableView didDeselectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSLog(@"取消选中单元格 %ld,%ld", (long)indexPath.section, (long)indexPath.row);
}

//可以显示编辑状态，当手指在单元格上移动时
- (void) tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    
    //删除数据源对应的数据
    [_arrayData removeObjectAtIndex:indexPath.row];
    
    //数据源更新
    [_tableView reloadData];
    
    NSLog(@"删除");
}


//单元格显示效果协议
- (UITableViewCellEditingStyle) tableView:(UITableView*)tableView editingStyleForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    //UITableViewCellEditingStyleDelete 删除状态
    //UITableViewCellEditingStyleInsert 添加状态
    //UITableViewCellEditingStyleNone 啥都没状态
    //默认为删除
    //UITableViewCellEditingStyleInsert | UITableViewCellEditingStyleDelete 多选状态
    return UITableViewCellEditingStyleDelete;
}

- (void) pressEdit {
    _isEdit = YES;
    self.navigationItem.rightBarButtonItem = _buttonFinish;
    [_tableView setEditing:YES];
    self.navigationItem.leftBarButtonItem = _buttonDelete;
}

- (void) pressFinish {
    _isEdit = NO;
    self.navigationItem.rightBarButtonItem = _buttonEdit;
    [_tableView setEditing:NO];
    self.navigationItem.leftBarButtonItem = nil;
}

- (NSInteger) tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _arrayData.count;
}

//默认组数返回1
- (NSInteger) numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (UITableViewCell*) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSString* strID = @"ID";
    
    //尝试获取可复用的单元格
    //如果得不到，返回为nil
    UITableViewCell* cell = [_tableView dequeueReusableCellWithIdentifier:strID];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:strID];
    }
    
    //单元格文字赋值
    cell.textLabel.text = [_arrayData objectAtIndex:indexPath.row];
    //设置子文字标题
    cell.detailTextLabel.text = @"子标题";
    
    //向单元格上添加图片
    NSString* str = [NSString stringWithFormat:@"%ld.jpg", indexPath.row % 5 + 1];
    
    UIImage* image = [UIImage imageNamed:str];
    
    //UIImageView* iView = [[UIImageView alloc] initWithImage:image];
    //设置默认的图标信息
    cell.imageView.image = image;
    
    return cell;
    
}

//设置单元格高度
- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(nonnull NSIndexPath *)indexPath {
    return 60;
}

@end
