//
//  ViewController.m
//  手动布局视图
//
//  Created by 张佳乔 on 2021/6/10.
//

#import "ViewController.h"
#import "SuperView.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //创建父亲视图
    SuperView* sView = [[SuperView alloc] init];
    
    sView.frame = CGRectMake(20, 20, 180, 280);
    
    sView.backgroundColor = [UIColor blueColor];
    
    [self.view addSubview:sView];
    
    sView.tag = 101;
    
    //调用SuperView的函数
    [sView createSubViews];
    
    //放大按钮
    UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    button.frame = CGRectMake(240, 480, 80, 40);
    
    [button setTitle:@"放大" forState:UIControlStateNormal];
    
    [button addTarget:self action:@selector(pressLarge) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:button];
    
    //缩小按钮
    UIButton* button02 = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    button02.frame = CGRectMake(240, 520, 80, 40);
    
    [button02 setTitle:@"缩小" forState:UIControlStateNormal];
    
    [button02 addTarget:self action:@selector(pressSmall) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:button02];
    
}

//放大父亲视图
- (void) pressLarge {
    
    SuperView* sView = (SuperView*)[self.view viewWithTag:101];
    
    //放大动画效果
    //p1:动画时间
    //p2:新图片的位置 
    [UIView animateWithDuration:0.5 animations:^{
        sView.frame = CGRectMake(20, 20, 300, 480);
    }];
    
}

//缩小父亲视图
- (void) pressSmall {
    SuperView* sView = (SuperView*)[self.view viewWithTag:101];
    
    [UIView animateWithDuration:0.5 animations:^{
        sView.frame = CGRectMake(20, 20, 180, 280);
    }];
}

@end
