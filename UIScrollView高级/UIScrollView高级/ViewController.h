//
//  ViewController.h
//  UIScrollView高级
//
//  Created by 张佳乔 on 2021/6/10.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController
//当前视图控制器要实现协议UIScrollView的协议函数
<UIScrollViewDelegate> {
    //定义一个滚动视图成员变量
    UIScrollView* _scrollView;
}


@end

