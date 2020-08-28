#include <boost/bind.hpp>
#include <gazebo/rendering/Visual.hh>
#include <gazebo/common/common.hh>
#include <ignition/transport/Node.hh>
#include "gazebo/common/Plugin.hh"
#include "gazebo/transport/Node.hh"

namespace gazebo
{
    class ChangeGreenLightVisualPlugin : public VisualPlugin
    {
    public:
        void Load(rendering::VisualPtr _parent, sdf::ElementPtr _sdf) override
        {
            gzmsg << "Loading nav lights visuals plugin";
            this->model = _parent; //Initialize parent model element
            // Subscribe to ContainPlugin output
            std::string topic("mis9/contain");
            std::function<void(const ignition::msgs::Boolean &)> cb =
                [ = ](const ignition::msgs::Boolean & _msg)
            {
                ChangeGreenLightVisualPlugin::OnContainPluginMsg(_msg);
            };
            const bool containSub = this->node.Subscribe(topic, cb);
            if (!containSub)
            {
                gzerr << "Failed to subscribe to [" << topic << "]\n";
            }

        }

        void OnContainPluginMsg(const ignition::msgs::Boolean &_msg)
        {
            common::Color green(0, 1, 0);
            common::Color greenOff(0, 1, 0, 0.5);
            if (_msg.data())
            {
                gzmsg << "Setting visual to on\n";
                this->model->SetAmbient(green);
                this->model->SetDiffuse(green);
                this->model->SetEmissive(green);
            }
            else
            {
                gzmsg << "Setting visual to off\n";
                this->model->SetAmbient(greenOff);
                this->model->SetDiffuse(greenOff);
                this->model->SetEmissive(greenOff);
            }
        }

    private:
        ignition::transport::Node node;
        rendering::VisualPtr model;
    };
    GZ_REGISTER_VISUAL_PLUGIN(ChangeGreenLightVisualPlugin);
}