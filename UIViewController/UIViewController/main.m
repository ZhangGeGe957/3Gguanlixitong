//
//  main.m
//  UIViewController
//
//  Created by 张佳乔 on 2021/6/7.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"

//整个App程序的主函数，入口函数
int main(int argc, char * argv[]) {
    NSString * appDelegateClassName;
    
    //自动内存释放池
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
        appDelegateClassName = NSStringFromClass([AppDelegate class]);
    }
    
    //UIKit框架结构的启动函数
    //参数一：argc，启动时带有参数的个数
    //参数二：argv，参数列表
    //参数三：要求传入一个主框架类类名，如果参数为nil，系统会自动用默认的框架类作为主框架类名
    //参数四：主框架的代理类对象
    return UIApplicationMain(argc, argv, nil, appDelegateClassName);
}
