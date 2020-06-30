#import <UIKit/UIKit.h>

@class PGPhotoEditorView;

@interface TGPhotoAvatarCropView : UIView

@property (nonatomic, readonly)  PGPhotoEditorView *fullPreviewView;

@property (nonatomic, strong) UIImage *image;

@property (nonatomic, readonly) CGSize originalSize;
@property (nonatomic, assign) CGRect cropRect;
@property (nonatomic, assign) UIImageOrientation cropOrientation;
@property (nonatomic, assign) bool cropMirrored;

@property (nonatomic, copy) void(^croppingChanged)(void);
@property (nonatomic, copy) void(^interactionBegan)(void);
@property (nonatomic, copy) void(^interactionEnded)(void);

@property (nonatomic, copy) void(^tapped)(void);

@property (nonatomic, readonly) bool isTracking;
@property (nonatomic, readonly) bool isAnimating;

- (instancetype)initWithOriginalSize:(CGSize)originalSize screenSize:(CGSize)screenSize;

- (void)setSnapshotImage:(UIImage *)image;
- (void)setSnapshotView:(UIView *)snapshotView;

- (void)_replaceSnapshotImage:(UIImage *)image;

- (void)rotate90DegreesCCWAnimated:(bool)animated;
- (void)mirror;
- (void)resetAnimated:(bool)animated;

- (void)animateTransitionIn;
- (void)animateTransitionOutSwitching:(bool)switching;
- (void)transitionInFinishedFromCamera:(bool)fromCamera;

- (void)invalidateCropRect;

- (UIImage *)currentImage;

- (void)hideImageForCustomTransition;

- (CGRect)contentFrameForView:(UIView *)view;
- (CGRect)cropRectFrameForView:(UIView *)view;
- (UIImage *)croppedImageWithMaxSize:(CGSize)maxSize;
- (UIView *)cropSnapshotView;

- (void)updateCircleImageWithReferenceSize:(CGSize)referenceSize;

+ (CGSize)areaInsetSize;

@end
