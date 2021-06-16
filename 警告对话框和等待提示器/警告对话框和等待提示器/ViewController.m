//
//  ViewController.m
//  警告对话框和等待提示器
//
//  Created by 张佳乔 on 2021/6/9.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

//实现属性和成员变量的同步
@synthesize alertView = _alertView;
@synthesize activityIndicator = _activityIndicator;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    for (int i = 0; i < 2; i++) {
        UIButton* btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        
        btn.frame = CGRectMake(100, 100 + 100 * i, 100, 40);
        
        if (i == 0) {
            [btn setTitle:@"警告对话框" forState:UIControlStateNormal];
        } else {
            [btn setTitle:@"等待提示器" forState:UIControlStateNormal];
        }
        
        btn.tag = 101 + i;
        
        [btn addTarget:self action:@selector(pressBtn:) forControlEvents:UIControlEventTouchUpInside];
        
        [self.view addSubview:btn];
    }
}

- (void) pressBtn: (UIButton*) btn {
    //警告对话框创建
    if (btn.tag == 101) {
        //创建警告对话框
        //p1:对话框标题
        //p2:提示信息
        //p3:点击后的风格
        _alertView = [UIAlertController alertControllerWithTitle:@"警告" message:@"您的手机电量过低，即将关机，请保存好数据" preferredStyle:UIAlertControllerStyleAlert];
        
        //点击按钮响应事件
        //p1:选项文字
        //p2:点击后的风格
        //p3:响应的事件,直接写在里面
        [_alertView addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault
            handler:^(UIAlertAction * _Nonnull action) {
            
            [self press];
            
        }]];
        
        [_alertView addAction:[UIAlertAction actionWithTitle:@"取消" style:UIAlertActionStyleDefault handler:nil]];
        
        //弹出警告对话框
        [self presentViewController:_alertView animated:true completion:nil];
        
    } else {     //创建等待提示器
        
        _activityIndicator = [[UIActivityIndicatorView alloc] initWithFrame:CGRectMake(100, 300, 80, 80)];
        
        //设置等待提示器的颜色
        _activityIndicator.color = [UIColor orangeColor];
        
        //设置等待提示器的样式,大或者中
        _activityIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyleMedium;
        
        //开启动画，必须调用，否则无法显示
        [_activityIndicator startAnimating];
        
        [self.view addSubview:_activityIndicator];
    }
}

- (void) press {
    NSLog(@"cool");
}

@end
