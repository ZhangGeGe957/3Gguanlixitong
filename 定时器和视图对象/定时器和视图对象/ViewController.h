//
//  ViewController.h
//  定时器和视图对象
//
//  Created by 张佳乔 on 2021/6/7.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController {
    
    //定义一个定时器对象
    //可以在每隔固定时间发送一个消息
    //通过此消息来调用相应的时间函数
    //通过此函数可在固定的时间段来完成一个根据时间间隔的任务
    NSTimer* _timerView;   //私有
}

//定时器的属性对象
@property (retain, nonatomic) NSTimer* timerView;   //共有

@end

