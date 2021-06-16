//
//  ViewController.m
//  UISwitch
//
//  Created by 张佳乔 on 2021/6/7.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

//同步属性和成员变量
@synthesize mySwitch = _mySwitch;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //创建一个开关对象
    //继承于UIView的
    _mySwitch = [[UISwitch alloc] init];
    
    //苹果官方的控件的位置设置
    //设置x，y的值可以改变
    //宽度和高度值无法改变，即你改变了也没用
    _mySwitch.frame = CGRectMake(100, 100, 80, 40);
    
    //开关状态设置属性
    //YES：开启状态
    //NO：关闭状态
    _mySwitch.on = YES;
    
    //也可使用set函数
    [_mySwitch setOn:YES];
    
    //设置开关状态
    //p1:状态设置
    //p2:是否开启动画效果
    [_mySwitch setOn:YES animated:YES];
    
    [self.view addSubview:_mySwitch];
    
    //设置开启状态的风格颜色
    [_mySwitch setOnTintColor:[UIColor orangeColor]];
    
    //设置开关圆钮的风格颜色
    [_mySwitch setThumbTintColor:[UIColor blueColor]];
    
    //设置整体风格颜色
    [_mySwitch setTintColor:[UIColor purpleColor]];
    
    //向开关控件添加事件函数
    //p1:函数实现对象
    //p2:函数对象
    //p3:事件响应时的事件类型UIControlEventValueChanged：状态发生变化时触发函数
    [_mySwitch addTarget:self action:@selector(swChange:) forControlEvents:UIControlEventValueChanged];
    
}

//参数传入开关对象本身
- (void) swChange:(UISwitch*) sw {
    //on表示当前结束的状态
    if (sw.on == YES) {
        NSLog(@"开关被打开！");
    } else {
        NSLog(@"开关被关闭！");
    }
    NSLog(@"开关状态发生变化！");
}
@end
