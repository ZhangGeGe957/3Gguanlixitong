//
//  ViewController.h
//  自动布局子视图
//
//  Created by 张佳乔 on 2021/6/10.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController {
    //创建父亲视图对象
    UIView* _superView;
    //左上角
    UILabel* _label01;
    //右上角
    UILabel* _label02;
    //右下角
    UILabel* _label03;
    //左下角
    UILabel* _label04;
    //中间
    UIView* _viewCenter;
}


@end

