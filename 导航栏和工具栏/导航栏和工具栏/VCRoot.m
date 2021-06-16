//
//  VCRoot.m
//  导航栏和工具栏
//
//  Created by 张佳乔 on 2021/6/13.
//

#import "VCRoot.h"
#import "VCSecond.h"

@interface VCRoot ()

@end

@implementation VCRoot

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor orangeColor];
    
    //设置导航栏风格颜色
    //UIBarStyleBlack：黑色风格，半透明风格
    self.navigationController.navigationBar.barStyle = UIBarStyleDefault;
    
    //将风格设置为不透明
    self.navigationController.navigationBar.translucent = NO;
    
    //设置导航栏的颜色
    self.navigationController.navigationBar.barTintColor = [UIColor redColor];
    
    //设置导航元素项目按钮的风格颜色
    self.navigationController.navigationBar.tintColor = [UIColor greenColor];
    
    //隐藏导航栏
    //self.navigationController.navigationBar.hidden = YES;
    //二选一 self.navigationController.navigationBarHidden = YES;
    
    self.title = @"根视图";
    
    UIBarButtonItem* button = [[UIBarButtonItem alloc] initWithTitle:@"右侧按钮" style:UIBarButtonItemStylePlain target:self action:nil];
    
    self.navigationItem.rightBarButtonItem = button;
    
    //显示工具栏对象
    //默认工具栏是隐藏的
    self.navigationController.toolbarHidden = NO;
    
    //设置工具栏是否透明
    self.navigationController.toolbar.translucent = NO;
    
    //创建三个工具栏按钮
    UIBarButtonItem* button01 = [[UIBarButtonItem alloc] initWithTitle:@"left" style:UIBarButtonItemStylePlain target:nil action:nil];
    
    UIBarButtonItem* button02 = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemCamera target:self action:@selector(pressNext)];
    
    UIButton* buttonImage = [UIButton buttonWithType:UIButtonTypeCustom];
    
    [buttonImage setImage:[UIImage imageNamed:@""] forState:UIControlStateNormal];
    
    buttonImage.frame = CGRectMake(0, 0, 60, 60);
    
    UIBarButtonItem* button03 = [[UIBarButtonItem alloc] initWithCustomView:buttonImage];
    
    //固定宽度占位按钮
    UIBarButtonItem* buttonfree01 = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFixedSpace target:nil action:nil];
    
    buttonfree01.width = 80;
    
    //创建自动计算宽度按钮
    UIBarButtonItem* buttonfree02 = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemFlexibleSpace target:nil action:nil];
    
    
    //按钮数组创建
    NSArray* arrayButtons = [NSArray arrayWithObjects:button01, buttonfree02, button02, buttonfree02, button03, nil];
    
    self.toolbarItems = arrayButtons;
    
}

- (void) pressNext {
    
    VCSecond* vc = [[VCSecond alloc] init];
    
    [self.navigationController pushViewController:vc animated:YES];
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
