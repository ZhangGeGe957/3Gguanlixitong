//
//  ViewController.m
//  UIView层级关系
//
//  Created by 张佳乔 on 2021/6/7.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //创建三个视图对象
    UIView* view01 = [[UIView alloc] init];
    
    view01.frame = CGRectMake(100, 100, 150, 150);
    
    view01.backgroundColor = [UIColor blueColor];
    
    UIView* view02 = [[UIView alloc] init];
    
    view02.frame = CGRectMake(125, 125, 150, 150);
    
    view02.backgroundColor = [UIColor orangeColor];
    
    UIView* view03 = [[UIView alloc] init];
    
    view03.frame = CGRectMake(150, 150, 150, 150);
    
    view03.backgroundColor = [UIColor greenColor];
    
    //将三个视图对象显示到屏幕上
    //并且添加到父亲视图上
    //哪一个视图被先添加到父亲视图中，就会先绘制哪一个视图
    //哪一个视图被最后一个添加到父亲视图中，就最后绘制哪一个视图
    [self.view addSubview:view01];
    
    [self.view addSubview:view02];

    [self.view addSubview:view03];
    
    //将某一个视图调整到最前面显示
    //参数：UIView对象，调整哪一个视图到最前方
    [self.view bringSubviewToFront:view03];
    
    //将某一个视图调整到最后显示
    //参数：UIView对象，调整哪一个视图到最后方
    [self.view sendSubviewToBack:view01];
    
    //subviews管理所有self.view的子视图的数组，根据视图显示在屏幕上的层级来分，最后的视图就是一号元素
    UIView* viewFront = self.view.subviews[2];
    
    UIView* viewBack = self.view.subviews[0];
    
    if (viewBack == view01) {
        NSLog(@"相等！");
    }
    //每一个视图都只有一个父亲（superview），但是它可以有多个儿子（subviews数组）
    
    [view01 removeFromSuperview];
}


@end
