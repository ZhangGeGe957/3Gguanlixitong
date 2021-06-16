//
//  ViewController.h
//  UITextField
//
//  Created by 张佳乔 on 2021/6/9.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController <UITextFieldDelegate> {
    //定义一个textField
    //文本输入区域
    //例如：用户名，密码等需要输入文本文字的内容区域
    //只能输入单行的文字，不能输入或显示多行
    UITextField* _textField;
    
    UITextField* _key;
}

//定义属性
@property (retain, nonatomic) UITextField* textField;
@property (retain, nonatomic) UITextField* key;

@end

