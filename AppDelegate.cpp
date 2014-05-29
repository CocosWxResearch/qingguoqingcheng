#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director ����
    auto director = Director::getInstance();

	// ������
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::createWithRect("PlayerThePlane", Rect(0, 0, 480, 800)); // ������ + ��߹��
		
		/*setFrameZoomFactor ���������������Ϊ�е��ƶ��豸��Ļ�ֱ��ʷǳ���  
����ipad3��̫��Ļ��ڵ����Ͽ���ȫ�ˣ�������setFrameZoomFactor�ѳ��򴰿���С  
���ԣ��������ֻ����win32,mac,linux����ʱ���õ�  */
		glview->setFrameZoomFactor(0.8f);			//�Ѵ�����С��ʵ�ʴ��ڴ�С��0.8��  ������������Ļ����Ա�����ֻ��Linux��window����Ч
		director->setOpenGLView(glview);

		// 1.LOOK �ú������Զ�����ƿ�ߺ����ŷ�ʽ��Ӧ�ֻ���Ļ��������Ϸ�ֱ��� ����ƿ���Ƹߣ����ŷ�ʽ����
		glview->setDesignResolutionSize(480, 800, ResolutionPolicy::NO_BORDER); 
    }

    // turn on display FPS ��ӡ֡�ʣ���ϣ�����½����г��ֵ� ��ע�͵� ��������false
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this һ��60֡
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object ��������
    auto scene = HelloWorld::createScene();

    // run �����ó�����ʼ����
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
