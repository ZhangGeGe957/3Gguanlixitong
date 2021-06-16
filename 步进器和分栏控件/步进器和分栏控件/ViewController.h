//
//  ViewController.h
//  步进器和分栏控件
//
//  Created by 张佳乔 on 2021/6/8.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController {
    //定义步进器对象
    //按照一定的数字来调整某个数据
    UIStepper* _stepper;
    
    //分栏控制器定义
    UISegmentedControl* _segControl;
}

//属性的定义
@property (retain, nonatomic) UIStepper* stepper;
@property (retain, nonatomic) UISegmentedControl* segControl;

@end

