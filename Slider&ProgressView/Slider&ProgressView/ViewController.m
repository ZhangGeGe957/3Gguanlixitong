//
//  ViewController.m
//  Slider&ProgressView
//
//  Created by 张佳乔 on 2021/6/7.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize slider = _slider;
@synthesize pView = _progressView;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //进度条的创建
    _progressView = [[UIProgressView alloc] init];
    
    //进度条的位置大小设置
    //进度条的高度是不可以变化的
    _progressView.frame = CGRectMake(50, 100, 200, 40);
    
    //设置进度条已完成风格的风格颜色值
    _progressView.progressTintColor = [UIColor orangeColor];
    
    //设置进度条未完成部分的风格颜色值
    _progressView.trackTintColor = [UIColor redColor];
    
    //设置进度条的进度值
    //范围从0～1
    //最小值为0
    //最大值为1
    _progressView.progress = 0.5;
    
    //设置进度条的风格特征
    _progressView.progressViewStyle = UIProgressViewStyleDefault;
    
    [self.view addSubview:_progressView];
    
    
    
    
    //创建滑动条对象
    _slider = [[UISlider alloc] init];
    
    //位置设置，高度不可变更
    _slider.frame = CGRectMake(10, 200, 300, 40);
    
    //设置滑动条最大值
    _slider.maximumValue = 100;
    
    //设置滑动条最小值，可以为负值
    _slider.minimumValue = 0;
    
    //设置滑动条的滑块位置float值
    _slider.value = 50;
    
    //左侧滑条背景颜色
    _slider.minimumTrackTintColor = [UIColor blueColor];
    
    //右侧滑条背景颜色
    _slider.maximumTrackTintColor = [UIColor greenColor];
    
    //设置滑块的颜色
    _slider.thumbTintColor = [UIColor orangeColor];
    
    //对滑动条添加事件函数
    [_slider addTarget:self action:@selector(pressSlider) forControlEvents:UIControlEventValueChanged];
    
    [self.view addSubview:_slider];
}

- (void) pressSlider {
    //使进度条跟着滑动条一起移动，注意进度条的区间值只能为0～1，而滑动条区间可以无限,所以要求平均值
    _progressView.progress = (_slider.value - _slider.minimumValue) / (_slider.maximumValue - _slider.minimumValue);
    
    NSLog(@"value = %lf", _slider.value);
}

@end
