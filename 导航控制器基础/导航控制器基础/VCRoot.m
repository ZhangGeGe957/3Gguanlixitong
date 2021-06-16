//
//  VCRoot.m
//  导航控制器基础
//
//  Created by 张佳乔 on 2021/6/13.
//

#import "VCRoot.h"

@interface VCRoot ()

@end

@implementation VCRoot

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //设置页面背景颜色
    self.view.backgroundColor = [UIColor orangeColor];
    
    //设置导航栏的标题
    self.title = @"根视图";
    
    //设置导航元素项目的标题
    //如果没有设置navigationItem.title，为nil
    //系统会使用self.title作为标题
    //如果navigationItem.title不为空
    //将navigationItem.title设置为标题内容
    self.navigationItem.title = @"Title";
    
    //创建一个导航栏左侧的按钮
    //根据title文字来创建按钮
    //p1:按钮上的文字
    //p2:按钮风格
    //p3:事件拥有者
    //p4:按钮事件
    //UIBarButtonItemStyleDone自定义风格
    UIBarButtonItem* leftButton = [[UIBarButtonItem alloc] initWithTitle:@"左侧" style:UIBarButtonItemStyleDone target:self action:@selector(pressLeft)];
    
    //将导航元素项的左侧按钮赋值
    self.navigationItem.leftBarButtonItem = leftButton;
    
    //创建一个导航栏右侧的按钮
    //根据系统风格来创建按钮
    //只需要指定风格样式，系统风格的按钮内容或标题文字不能改变
    //p1:按钮风格
    //p2:事件拥有者
    //p3:按钮事件
    UIBarButtonItem* rightButton = [[UIBarButtonItem alloc] initWithBarButtonSystemItem:UIBarButtonSystemItemClose target:self action:@selector(pressRight)];
    
    self.navigationItem.rightBarButtonItem = rightButton;
    
    //标签对象
    UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(10, 10, 50, 40)];
    
    label.text = @"test";
    
    label.textAlignment = NSTextAlignmentCenter;
    
    //将任何类型的控件添加到导航按钮的方法
    UIBarButtonItem* Button = [[UIBarButtonItem alloc] initWithCustomView:label];
    
    //创建按钮数组
    NSArray* buttonArray = [NSArray arrayWithObjects:rightButton, Button, nil];
    
    //将右侧按钮数值赋值
    self.navigationItem.rightBarButtonItems = buttonArray;
}

- (void) pressLeft {
    NSLog(@"左侧按钮被按下!");
}

- (void) pressRight {
    NSLog(@"右侧按钮被按下！");
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
