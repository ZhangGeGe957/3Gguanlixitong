//
//  ViewController.m
//  滚动视图
//
//  Created by 张佳乔 on 2021/6/9.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //得到当前屏幕的尺寸
    CGRect rect_screen = [[UIScreen mainScreen] bounds];
    CGSize size_screen = rect_screen.size;
    
    //定义并创建一个滚动视图
    //可以对视图内容进行滚屏查看功能
    UIScrollView* sv = [[UIScrollView alloc] init];
    
    //设置滚动视图的位置，使用矩形来定位视图位置
    sv.frame = CGRectMake(0, 0, size_screen.width, size_screen.height);
    
    //是否按照整页来滚动视图，每次显示都是这整张图片
    sv.pagingEnabled = YES;
    //是否可以开启滚动效果
    sv.scrollEnabled = YES;
    //设置画布大小，画布显示在滚动视图内部，一般大于Frame的大小
    sv.contentSize = CGSizeMake(size_screen.width * 5, size_screen.height);
    //是否可以边缘弹动效果
    sv.bounces = YES;
    //开启横向弹动效果
    sv.alwaysBounceHorizontal = YES;
    //开始纵向弹动效果
    sv.alwaysBounceVertical = YES;
    //显示横向滚动条
    sv.showsHorizontalScrollIndicator = YES;
    //显示纵向滚动条
    sv.showsVerticalScrollIndicator = YES;
    //设置背景颜色
    sv.backgroundColor = [UIColor yellowColor];
    
    [self.view addSubview:sv];
    
    //使用循环创建5张图片视图
    for (int i = 0; i < 5; i++) {
        NSString* strName = [NSString stringWithFormat:@"%d.jpg", i + 1];
        
        UIImage* image = [UIImage imageNamed:strName];
        
        UIImageView* iView = [[UIImageView alloc] initWithImage:image];
        
        iView.frame = CGRectMake(size_screen.width * i, 0, size_screen.width, size_screen.height);
        
        //将图片放到滚动视图中
        [sv addSubview:iView];
        
    }
}


@end
