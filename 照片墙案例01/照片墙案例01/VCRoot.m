//
//  VCRoot.m
//  照片墙案例01
//
//  Created by 张佳乔 on 2021/6/13.
//

#import "VCRoot.h"
#import "VCImageShow.h"

@interface VCRoot ()

@end

@implementation VCRoot

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"照片墙";
    
    //使导航栏不透明
    self.navigationController.navigationBar.translucent = NO;
    
    UIScrollView* sv = [[UIScrollView alloc] init];
    
    //设置位置大小
    sv.frame = CGRectMake(5, 10, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height);
    
    //设置画布大小
    sv.contentSize = CGSizeMake([UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height * 1.5);
    
    //是否显示滚动条
    sv.showsVerticalScrollIndicator = NO;
    
    //打开交互事件
    sv.userInteractionEnabled = YES;
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    for (int i = 0; i < 5; i++) {
        NSString* strName = [NSString stringWithFormat:@"%d.jpg", i + 1];
        
        UIImage* image = [UIImage imageNamed:strName];
        
        UIImageView* iView = [[UIImageView alloc] initWithImage:image];
        
        iView.frame = CGRectMake(3 + (i % 4) * 100, (i / 4) * 130 + 10, [UIScreen mainScreen].bounds.size.width / 4 - 10, 120);
        
        [sv addSubview:iView];
        
        //开启交互模式
        iView.userInteractionEnabled = YES;
        
        //创建点击手势
        UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(pressTap:)];
        
        //单次点击
        tap.numberOfTapsRequired = 1;
        
        //单个手指
        tap.numberOfTouchesRequired = 1;
        
        [iView addGestureRecognizer:tap];
        
        //图像对象的tag值
        iView.tag = 101 + i;
    }
    
    [self.view addSubview:sv];
    
}

- (void) pressTap:(UITapGestureRecognizer*) tap {
    
    UIImageView* imageView = (UIImageView*)tap.view;
    
    //创建视图控制器
    VCImageShow* imageShow = [[VCImageShow alloc] init];
    
    imageShow.imageTag = imageView.tag;
    
    [self.navigationController pushViewController:imageShow animated:YES];
    
}


/*方法二:
- (void) pressTap:(UITapGestureRecognizer*) tap {
    UIImageView* imageView = (UIImageView*)tap.view;
    
    //创建显示视图控制器
    VCImageShow* imageShow = [[VCImageShow alloc] init];
    
    //点击的图像视图赋值
    imageShow.image = imageView.image;
    
    //将控制器推出
    [self.navigationController pushViewController:imageShow animated:YES];
}
 */

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
