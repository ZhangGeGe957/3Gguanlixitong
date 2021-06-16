//
//  ViewController.m
//  视图控制器的使用
//
//  Created by 张佳乔 on 2021/6/7.
//

#import "ViewController.h"
#import "ViewController02.h"

@interface ViewController ()

@end

@implementation ViewController

//当屏幕被点击时，调用此函数
- (void) touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    //创建视图控制器二
    ViewController02* vc = [[ViewController02 alloc] init];
    
    //弹出的页面充满屏幕
//    通过设置presenting VC的modalPresentationStyle属性，我们可以设置弹出View Controller时的风格，有以下四种风格，其定义如下：
//
//    typedef enum {
//        UIModalPresentationFullScreen = 0,
//        UIModalPresentationPageSheet,
//        UIModalPresentationFormSheet,
//        UIModalPresentationCurrentContext,
//    } UIModalPresentationStyle;
    vc.modalPresentationStyle = UIModalPresentationFullScreen;
    
    //显示一个新的视图控制器到屏幕上
    //p1:新的视图控制器对象
    //p2:是否使用切换动画效果
    //p3:切换结束后功能调用，不需要传nil值即可
    [self presentViewController:vc animated:YES completion:nil];
}

//第一次加载视图时调用
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.view.backgroundColor = [UIColor orangeColor];
    
    NSLog(@"viewDidLoad！第一次加载视图！");
}

//当视图控制器的视图即将显示时，调用此函数
//视图分为：1.显示前（不显示） 2.正在处于显示状态 3.已经被隐藏
//参数：表示是否用动画切换后显示
//每一次视图显示时都要被调用
- (void) viewWillAppear:(BOOL)animated {
    NSLog(@"viewWillAppear!视图即将显示！");
    
}

//视图即将消失时，调用此函数
//参数：表示是否用动画切换后消失
//当前的状态：视图还是显示在屏幕上的
- (void) viewWillDisappear:(BOOL)animated {
    NSLog(@"viewWillAppear!视图即将消失！");
}

//当视图已经显示到屏幕后的瞬间调用此函数
//参数：表示是否用动画切换显示的
//当前状态已经显示到屏幕上了
- (void) viewDidAppear:(BOOL)animated {
    NSLog(@"viewDidAppear!视图已经显示！");
}

//当前视图已经从屏幕上消失
//参数：表示是否用动画切换显示的
//当前的状态：视图已经从屏幕上消失
- (void) viewDidDisappear:(BOOL)animated {
    NSLog(@"viewDidDisappear!视图已经消失！");
}

//内存过低警告接受函数
- (void) didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

@end
