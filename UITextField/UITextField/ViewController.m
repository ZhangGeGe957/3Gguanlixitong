//
//  ViewController.m
//  UITextField
//
//  Created by 张佳乔 on 2021/6/9.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize textField = _textField;
@synthesize key = _key;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    //创建一个文本输入区对象
    self.textField = [[UITextField alloc] init];
    
    self.key = [[UITextField alloc] init];
    
    //设定文本输入区的位置
    self.textField.frame = CGRectMake(100, 100, 180, 40);
    
    self.key.frame = CGRectMake(100, 200, 180, 40);
    
    //设置textField的文字内容
    //self.textField.text = @"用户名:";
    
    
    //设置文字的字体大小
    self.textField.font = [UIFont systemFontOfSize:15];
    
    self.key.font = [UIFont systemFontOfSize:15];
    
    //设置字体的颜色
    self.textField.textColor = [UIColor orangeColor];
    
    self.key.textColor = [UIColor orangeColor];
    
    //设置边框的风格
    //UITextBorderStyleRoundedRect  圆角风格(默认)
    //UITextBorderStyleLine    线框风格
    //UITextBorderStyleBezel   线框
    //UITextBorderStyleNone    无边框风格
    self.textField.borderStyle = UITextBorderStyleRoundedRect;
    
    self.key.borderStyle = UITextBorderStyleRoundedRect;
    
    //设置虚拟键盘风格
    //UIKeyboardTypeDefault  默认风格
    //UIKeyboardTypePhonePad   字母和数字组合风格
    //UIKeyboardTypeNumberPad    纯数字风格
    self.textField.keyboardType = UIKeyboardTypeDefault;
    
    self.key.keyboardType = UIKeyboardTypeDefault;
    
    //提示文字信息
    //当text属性为空时，显示此条信息
    //浅灰色提示文字
    self.textField.placeholder = @"请输入用户名。。。";
    
    self.key.placeholder = @"请输入密码。。。";
    
    //是否作为密码输入
    //YES：加密处理
    //NO：正常显示输入文字
    self.textField.secureTextEntry = NO;
    
    self.key.secureTextEntry = YES;
    
    
    [self.view addSubview:_textField];
    
    [self.view addSubview:_key];
    
    //设置代理，才能用下面的函数
    self.textField.delegate = self;
    
    self.key.delegate = self;
    
}

- (void) textFieldDidBeginEditing:(UITextField *)textField {
    NSLog(@"开始编辑！");
}

- (void) textFieldDidEndEditing:(UITextField *)textField {
    NSLog(@"结束编辑！");
}

//是否可以进行输入
//如果返回值是YES：可以进行输入，默认为YES
//NO：不能输入文字，无法弹出键盘
- (BOOL) textFieldShouldBeginEditing:(UITextField *)textField {
    return YES;
}

//是否可以结束输入
//如果返回值是YES：可以进行输入，默认为YES
//NO：不能结束输入文字，收不回键盘
- (BOOL) textFieldShouldEndEditing:(UITextField *)textField {
    //若输入的个数小于6，则不会收回键盘
    if (_textField.text.length < 6) {
        return NO;
    }
    return YES;
}


//点击屏幕空白处调用此函数
- (void) touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    //使虚拟键盘回收，不再作为第一消息响应者
    [_textField resignFirstResponder];
    
    [_key resignFirstResponder];
}


@end
