//
//  ViewController.m
//  tgsdgdfg
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
    
    UILabel* lb = [[UILabel alloc] init];
    lb.frame = CGRectMake(300, 300, 80, 40);
    lb.text = @"cool";
    
    [self.view addSubview:lb];
    
    
    UIButton* btn = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    btn.frame = CGRectMake(100, 100, 80, 40);
    [btn setTitle:@"按钮" forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(pressButton) forControlEvents:UIControlEventTouchUpInside];
    
    [self.view addSubview:btn];
}
- (void) pressButton {
    NSLog(@"");
}

@end
