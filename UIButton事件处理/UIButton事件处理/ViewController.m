//
//  ViewController.m
//  UIButton事件处理
//
//  Created by 张佳乔 on 2021/6/6.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void) createBtn {
    //创建圆角按钮
    UIButton* btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    btn.frame = CGRectMake(150, 100, 80, 40);
    
    [btn setTitle:@"按钮" forState:UIControlStateNormal];
    
    btn.backgroundColor = [UIColor grayColor];
    
    //向按钮添加事件
    //p1:”谁“来实现事件函数，实现着对象就是“谁”
    //p2:@selector（pressBtn）：方法对象，当按钮满足p3事件类型时，调用方法
    //p3:UIControlEvents：事件处理方法类型
    //UIControlEventTouchUpInside：当手指离开屏幕时，并且手指的位置在按钮范围内触发事件方法
    [btn addTarget:self action:@selector(pressBtn:) forControlEvents:UIControlEventTouchUpInside];
    
    //触碰时调用事件函数
    [btn addTarget:self action:@selector(touchDown) forControlEvents:UIControlEventTouchDown];
    
    [self.view addSubview:btn];
    
    UIButton* btn02 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    btn02.frame = CGRectMake(150, 300, 80, 40);
    
    [btn02 setTitle:@"按钮02" forState:UIControlStateNormal];
    
    //是可以多个按钮使用同一个事件函数来处理不同按钮的事件
    [btn02 addTarget:self action:@selector(pressBtn:) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:btn02];
    
    //设置按钮的标记值,相当于按钮界的身份证
    btn.tag = 101;
    btn02.tag = 102;
    
}

- (void) pressBtn02 {
    NSLog(@"按钮02被触碰!");
}

- (void) touchDown {
    NSLog(@"按钮被触碰！");
}

//参数为调用此函数按钮本身
- (void) pressBtn: (UIButton*) btn {
    if (btn.tag == 101) {
        NSLog(@"btn01 pressed");
    }
    if (btn.tag == 102) {
        NSLog(@"btn02 pressed");
    }
}

//- (void) pressBtn {
//    NSLog(@"按钮被按下！");
//}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self createBtn];
}


@end
