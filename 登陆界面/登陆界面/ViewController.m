//
//  ViewController.m
//  登陆界面
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
    
    //用户名提示标签创建
    _lbUserName = [[UILabel alloc] init];
    _lbUserName.frame = CGRectMake(20, 60, 80, 40);
    _lbUserName.text = @"用户名";
    _lbUserName.font = [UIFont systemFontOfSize:20];
    _lbUserName.textAlignment = NSTextAlignmentLeft;
    
    //密码提示标签创建
    _lbPassword = [[UILabel alloc] init];
    _lbPassword.frame = CGRectMake(20, 140, 80, 40);
    _lbPassword.text = @"密码";
    _lbPassword.font = [UIFont systemFontOfSize:20];
    _lbPassword.textAlignment = NSTextAlignmentLeft;
    
    //用户名输入框
    _tfUserName = [[UITextField alloc] init];
    _tfUserName.frame = CGRectMake(120, 60, 180, 40);
    _tfUserName.placeholder = @"请输入用户名";
    _tfUserName.borderStyle = UITextBorderStyleRoundedRect;
    
    //密码输入框
    _tfPassword = [[UITextField alloc] init];
    _tfPassword.frame = CGRectMake(120, 140, 180, 40);
    _tfPassword.placeholder = @"请输入密码";
    _tfPassword.borderStyle = UITextBorderStyleRoundedRect;
    _tfPassword.secureTextEntry = YES;
    
    //登陆和注册btn创建
    _btLogin = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _btLogin.frame = CGRectMake(120, 300, 80, 40);
    [_btLogin setTitle:@"登陆" forState:UIControlStateNormal];
    [_btLogin addTarget:self action:@selector(pressLogin) forControlEvents:UIControlEventTouchUpInside];
    
    
    _btRegister = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _btRegister.frame = CGRectMake(120, 360, 80, 40);
    [_btRegister setTitle:@"注册" forState:UIControlStateNormal];
    [_btRegister addTarget:self action:@selector(pressRegister) forControlEvents:UIControlEventTouchUpInside];
    
    //将所有的控件添加到视图中显示
    [self.view addSubview:_lbUserName];
    [self.view addSubview:_lbPassword];
    [self.view addSubview:_tfUserName];
    [self.view addSubview:_tfPassword];
    [self.view addSubview:_btLogin];
    [self.view addSubview:_btRegister];

}

//登陆事件函数
- (void) pressLogin {
    NSString* strName = @"admin";
    NSString* strPass = @"957520";
    
    //获取输入框中的用户文字
    NSString* strTextName = _tfUserName.text;
    NSString* strTextPass = _tfPassword.text;
    
    if ([strName isEqualToString:strTextName] && [strPass isEqualToString:strTextPass]) {
        NSLog(@"登陆成功！");
        
        UIAlertController* alView = [UIAlertController alertControllerWithTitle:@"提示" message:@"登陆成功！" preferredStyle:UIAlertControllerStyleAlert];
        
        [alView addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault
            handler:nil]];
        
        [self presentViewController:alView animated:true completion:nil];
        
    } else {
        NSLog(@"登陆失败！");
        
        UIAlertController* alView = [UIAlertController alertControllerWithTitle:@"提示" message:@"登陆失败！" preferredStyle:UIAlertControllerStyleAlert];
        
        [alView addAction:[UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault
            handler:nil]];
        
        [self presentViewController:alView animated:true completion:nil];
    }
}

//注册事件函数
- (void) pressRegister {
    NSLog(@"注册成功！");
}

//点击屏幕空白处调用此函数
- (void) touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    //使虚拟键盘回收，不再作为第一消息响应者
    [_tfUserName resignFirstResponder];
    
    [_tfPassword resignFirstResponder];
}

@end
