//
//  ViewController.m
//  步进器和分栏控件
//
//  Created by 张佳乔 on 2021/6/8.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize stepper =_stepper;
@synthesize segControl = _segControl;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //创建步进器对象
    _stepper = [[UIStepper alloc] init];
    
    //设置位置，宽高不能变更
    _stepper.frame = CGRectMake(100, 100, 80, 40);

    //设置步进器的最小值
    _stepper.minimumValue = 0;
    
    //设置步进器的最大值
    _stepper.maximumValue = 100;
    
    //设置步进器的当前值，默认为0
    _stepper.value = 10;
    
    //设置步进值，每次向前或者向后步进的步伐值
    _stepper.stepValue = 1;
    
    //是否可以重复响应事件操作,即一直按住它是否会执行加减
    _stepper.autorepeat = YES;
    
    //是否将步进结果通过事件函数响应出来，即它一直按住时是否会输出函数内容
    _stepper.continuous = YES;
    
    //添加事件函数
    //1.函数实现体
    //2.函数体
    //3.事件值改变状态
    [_stepper addTarget:self action:@selector(stepChange) forControlEvents:UIControlEventValueChanged];
    
    [self.view addSubview:_stepper];
    
    
    
    
    //创建分栏控件
    _segControl = [[UISegmentedControl alloc] init];
    
    //设置控件位置，宽度可变，高度不可变
    _segControl.frame = CGRectMake(10, 200, 300, 40);
    
    //添加一个按钮元素
    //p1:按钮选择文字
    //p2:按钮的索引位置
    //p3:是否有插入的动画效果
    [_segControl insertSegmentWithTitle:@"0元" atIndex:0 animated:NO];
    
    [_segControl insertSegmentWithTitle:@"5元" atIndex:1 animated:NO];
    
    [_segControl insertSegmentWithTitle:@"10元" atIndex:2 animated:NO];
    
    _segControl.backgroundColor = [UIColor orangeColor];
    
    [_segControl addTarget:self action:@selector(segChange) forControlEvents:UIControlEventValueChanged];
    
    //当前默认按钮索引设置
    _segControl.selectedSegmentIndex = 0;
    
    [self.view addSubview:_segControl];
}

- (void) segChange {
    NSLog(@"%d", _segControl.selectedSegmentIndex);
}

- (void) stepChange {
    NSLog(@"step press! value = %f", _stepper.value);
}

@end
