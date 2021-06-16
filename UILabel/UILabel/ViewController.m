   //
//  ViewController.m
//  UILabel
//
//  Created by 张佳乔 on 2021/6/6.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

//创建UI控件函数
- (void) createUI {
    //定义并且创建一个UILabel对象
    //UILabel是可以显示在屏幕上，并且可以显示文字的一种UI视图
    UILabel* label = [[UILabel alloc] init];
    
    //显示文字的赋值，字符串对象
    label.text = @"Hello World!";
    
    //设定label的显示位置
    label.frame = CGRectMake(100, 300, 160, 40);
    
    //设置label的背景颜色，clearColor表示透明的颜色
    label.backgroundColor = [UIColor clearColor];
    
    //设置全屏背景颜色
    self.view.backgroundColor = [UIColor grayColor];
    
    //将label显示到屏幕上
    [self.view addSubview:label];
    
    //设置label文字的大小，使用系统默认字体，大小为12
    label.font = [UIFont systemFontOfSize:24];
    
    //设置文字的颜色
    label.textColor = [UIColor blackColor];
    
    //label的高级属性
    //设定阴影的颜色
    label.shadowColor = [UIColor grayColor];
    
    //设置阴影的偏移量
    label.shadowOffset = CGSizeMake(5, 5);
    
    //设置text文字的对齐模式，默认为靠左对齐
    label.textAlignment = NSTextAlignmentCenter;
    
    //设定label文字显示的行数，默认值为：1，只用一行来显示
    //其它的>0的行数，文字会尽量按照设定的行数来显示
    //如果值为：0，iOS会对文字自动计算所需要的行数，按照需要的行数来显示文字
    label.numberOfLines = 0;
    
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
   
    //调用创建的createUI方法
    [self createUI];
}


@end
