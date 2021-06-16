//
//  VCImageShow.m
//  照片墙案例01
//
//  Created by 张佳乔 on 2021/6/13.
//

#import "VCImageShow.h"

@interface VCImageShow ()

@end

@implementation VCImageShow

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.title = @"图片展示";
    
    _imageView = [[UIImageView alloc] init];
    
    _imageView.frame = CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, [UIScreen mainScreen].bounds.size.height - 30);
    
    
    //方法二：
   // _imageView.image = _image;
    
    //方法三：
    _imageView.image = [UIImage imageNamed:[NSString stringWithFormat:@"%lu.jpg", _imageTag - 100]];
    
    
    //一个视图对象只能有一个根视图
    //当我们把视图添加到新的父亲上时
    //从原来的父亲视图中给删除掉
    [self.view addSubview:_imageView];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
