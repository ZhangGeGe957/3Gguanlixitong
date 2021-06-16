//
//  ViewController02.m
//  视图控制器的使用
//
//  Created by 张佳乔 on 2021/6/7.
//

#import "ViewController02.h"

@interface ViewController02 ()

@end

@implementation ViewController02

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //控制器二的颜色为橙色
    self.view.backgroundColor = [UIColor blueColor];
}

- (void) touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    //使当前的视图控制器消失掉
    //p1:是否有动画效果
    //p2:结束后是否调用功能block块操作
    [self dismissViewControllerAnimated:YES completion:nil];
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
