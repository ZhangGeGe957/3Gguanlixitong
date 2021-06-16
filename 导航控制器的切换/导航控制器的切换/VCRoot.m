//
//  VCRoot.m
//  导航控制器的切换
//
//  Created by 张佳乔 on 2021/6/13.
//

#import "VCRoot.h"
#import "VCSecond.h"

@interface VCRoot ()

@end

@implementation VCRoot

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //设置导航栏的透明度
    //默认透明度为YES：可透明
    //NO：使导航栏不透明
    self.navigationController.navigationBar.translucent = YES;
    
    //设置导航栏颜色
    //self.navigationController.navigationBar.barTintColor = [UIColor grayColor];
    
    self.view.backgroundColor = [UIColor blueColor];
    
    self.title = @"根视图";
    
    UIBarButtonItem* nextButton = [[UIBarButtonItem alloc] initWithTitle:@"下一级" style:UIBarButtonItemStylePlain target:self action:@selector(pressNextButton)];
    
    self.navigationItem.rightBarButtonItem = nextButton;
    
}

- (void) pressNextButton {
    //创建新的视图控制器
    VCSecond* vcSecond = [[VCSecond alloc] init];
    
    //使用当前视图控制器的导航控制器对象
    [self.navigationController pushViewController:vcSecond animated:YES];
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
