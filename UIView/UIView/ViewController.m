//
//  ViewController.m
//  UIView
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
    
    //创建一个UIView对象
    //UIView的iOS中的视图对象
    //显示在屏幕上的所有对象的基础类
    //所有显示在屏幕上的对象一定都继承于UIView
    //屏幕上能看到的对象都是UIView的子类
    //UIView是一个矩形对象，有背景颜色，可以显示，有层级关系
    UIView* view = [[UIView alloc] init];
    
    //设置UIView的位置
    view.frame = CGRectMake(100, 100, 100, 200);
    
    view.backgroundColor = [UIColor blueColor];
    
    //将新建的视图添加到父亲视图上
    //1.将新建的视图显示到屏幕上
    //2.将视图作为父亲视图的子视图管理起来
    [self.view addSubview:view];
    
    //是否隐藏视图对象
    //YES：不显示
    //NO：显示，默认值为NO
    view.hidden = NO;
    
    //设置视图的透明度
    //alpha = 1：不透明
    //alpha = 0：透明
    //alpha = 0.5： 半透明
    view.alpha = 0.5;
    
    self.view.backgroundColor = [UIColor orangeColor];
    
    //设置是否显示不透明
    view.opaque = NO;
    
    //将自己从父亲视图删除掉
    //1:从父亲视图的管理中删除
    //2:不会显示在屏幕上
    [view removeFromSuperview];
}


@end
