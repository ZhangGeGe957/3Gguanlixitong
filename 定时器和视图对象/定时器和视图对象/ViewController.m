//
//  ViewController.m
//  定时器和视图对象
//
//  Created by 张佳乔 on 2021/6/7.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

//属性和成员变量的同步
@synthesize timerView = _timerView;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //启动定时器按钮
    UIButton* btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    btn.frame = CGRectMake(150, 200, 80, 40);
    
    [btn setTitle:@"启动定时器" forState:UIControlStateNormal];
    
    [btn addTarget:self action:@selector(pressStart) forControlEvents:UIControlEventTouchUpInside];
    
    btn.backgroundColor = [UIColor greenColor];
    
    [self.view addSubview:btn];
    
    //停止计时器
    UIButton* btnStop = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    
    btnStop.frame = CGRectMake(150, 300, 80, 40);
    
    [btnStop setTitle:@"停止计时器" forState:UIControlStateNormal];
    
    [btnStop addTarget:self action:@selector(pressStop) forControlEvents:UIControlEventTouchUpInside];
    
    btnStop.backgroundColor = [UIColor redColor];
    
    [self.view addSubview:btnStop];
    
    UIView* view = [[UIView alloc] init];
    
    view.frame = CGRectMake(0, 0, 80, 80);
    
    view.backgroundColor = [UIColor orangeColor];
    
    [self.view addSubview:view];
    
    //设置view的标签值
    //通过父亲视图对象以及view的标签值可以获得相应的视图对象
    view.tag = 101;
    
}

//按下开始按钮函数
- (void) pressStart {
    
    //NSTimer的类方法创建一个定时器并且启动这个定时器
    //p1:每隔多长时间调用定时器函数，以秒为单位
    //p2:表示实现定时器函数的对象（指针）
    //p3:定时器函数对象
    //p4:可以传入定时器中的一个参数，无参数可以传nil
    //p5:定时器是否重复操作，YES为重复，NO只完成一次函数调用
    //返回值为一个新建好的定时器对象
    _timerView = [NSTimer scheduledTimerWithTimeInterval:0.01 target:self selector:@selector(updateTimer:) userInfo:@"张三" repeats:YES];
}

//定时器函数
//可以将定时器本身作为参数传入
- (void) updateTimer:(NSTimer*) timer {
    NSLog(@"test!!!name = %@", timer.userInfo);
    
    //tag最好从100开始
    UIView* view = [self.view viewWithTag:101];
    
    view.frame = CGRectMake(view.frame.origin.x + 1, view.frame.origin.y + 1, 80, 80);
}

//按下停止按钮函数
- (void) pressStop {
    if (_timerView != nil) {
        
        //停止定时器
        [_timerView invalidate];
    }
}


@end
